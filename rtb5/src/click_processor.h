#ifndef SRC_CLICK_PROCESSOR_H
#define SRC_CLICK_PROCESSOR_H

#include <string>
#include <boost/functional/hash.hpp>
#include "proto/click.pb.h"
#include "proto/campaign.pb.h"
#include "proto/union.pb.h"
#include "src/database.h"

namespace RTB5 {

class ClickProcessor {
 public:
  //
  bool Init();
  //
  bool Process(Click* click);

 private:
  //
  uint64_t GenerateClickID(const Click& click);
  //
  bool FindCampaign(const Click& click, const Campaign*& campaign, const Union*& upper_union);
  //
  std::string GenerateJumpUrl(const Click& click, const Union& upper_union);
  //
  bool Match(const Campaign& campaign, const std::string& url);
  //
  bool BindCampaign(const Campaign& campaign);

 private:
  //
  std::vector<Union> unions;
  //
  boost::hash<std::string> md5;
  //
  Database database;
};

} // RTB5

#endif // SRC_CLICK_PROCESSOR_H
