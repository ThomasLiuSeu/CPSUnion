
#include "src/click_processor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>

namespace RTB5 {
//  
bool ClickProcessor::Process(Click* click) {
  time_t now;
  time(&now);
  click->set_click_time(now);
  uint64_t click_id = GenerateClickID(*click);
  click->set_click_id(click_id);
  // 
  const Campaign* campaign;
  const Union* upper_union;
  if (FindCampaign(*click, campaign, upper_union)) {
    std::string jump_url = GenerateJumpUrl(*click, *upper_union);
    click->set_second_jump_url(jump_url);
    click->set_union_id(upper_union->union_id());
    click->set_campaign_id(campaign->campaign_id());
  } else {
    click->set_second_jump_url(click->origin_url());
  }
  if (!database.Insert(*click)) {
    LOG(ERROR) << "Insert Click Failed:" << click->Utf8DebugString();
  }
  return true;
}
//
bool ClickProcessor::Init() {
  if (!database.Open()) {
    LOG(ERROR) << "Database Open Failed!";
    return false;
  }
  if (!database.Load(&unions)) {
    LOG(ERROR) << "Load Unions Failed!";
    return false;
  } else {
    LOG(INFO) << "Load Unions :" << unions.size();
  }
  //
  std::vector<Campaign> campaigns;
  if (!database.Load(&campaigns)) {
    LOG(ERROR) << "Load Campaigns Failed!";
    return false;     
  } else {
    LOG(INFO) << "Load Campaigns :" << campaigns.size();
  }
  uint64_t bind_failed = 0;
  for (const auto& each_campaign : campaigns) {
    if (!BindCampaign(each_campaign)) {
      bind_failed++;
    }
  }
  LOG(ERROR) << "Campaigns bind falied :" << bind_failed;
  return true;
}
//
uint64_t ClickProcessor::GenerateClickID(const Click& click) {
  return (click.user_id() << 48) + ((click.click_time() & 0xFFFFFFFF) << 16) + (md5(click.tags()) & 0xFFFF);
}
//
std::string ClickProcessor::GenerateJumpUrl(const Click& click, const Union& upper_union) {
  std::string second_jump_url = upper_union.url_pattern();
  //
  boost::replace_all(second_jump_url, "{origin_url}", click.origin_url());
  //
  boost::replace_all(second_jump_url, "{tags}", boost::lexical_cast<std::string>(click.click_id()));
  return second_jump_url;
}
//
bool ClickProcessor::FindCampaign(const Click& click, const Campaign*& campaign, const Union*& upper_union) {
  for (const auto& each_union : unions) {
    for (const auto& each_campaign : each_union.campaigns()) {
      if (Match(each_campaign, click.origin_url())) {
        upper_union = &each_union;
        campaign = &each_campaign;
        return true;
      }
    }
  }
  return false;
}
//
bool ClickProcessor::BindCampaign(const Campaign& campaign) {
  for (auto& each_union : unions) {
    if (campaign.union_id() == each_union.union_id()) {
      Campaign* campaign_ptr = each_union.add_campaigns();
      *campaign_ptr = campaign;
      return true;
    }
  }
  return false;
}
//
bool ClickProcessor::Match(const Campaign& campaign, const std::string& url) {
  if (url.find(campaign.pattern()) == std::string::npos) {
    return false;
  } else {
    return true;
  }
}

} // RTB5