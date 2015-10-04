
#include "src/database.h"
#include <time.h>
#include <boost/lexical_cast.hpp>

namespace RTB5 {
  
typedef std::unique_lock<std::mutex>  MutexLock;

bool Database::Open() {
  rtb5 = mysql_init(NULL);
  if (!rtb5) {
    LOG(ERROR) << "Mysql init failed";
    return NULL;
  }
  mysql_options(rtb5, MYSQL_SET_CHARSET_NAME, "utf8");
  // TODO(cernwang)
  rtb5 = mysql_real_connect(rtb5, "127.0.0.1", "root", "abcdefg2008", "rtb5", 3306, NULL, 0);
  if (rtb5) {
    LOG(INFO) << "Connection success!";
    return true;
  } else {
    LOG(ERROR) << "Connection failed!";
    return false;
  }
}
 
void Database::Close() {
  mysql_close(rtb5);
}

bool Database::FetchRows(MYSQL* db, std::vector< std::map<std::string, std::string> >* rows) {
  bool success = true;
  int status = 0;
  while (status == 0) {
    MYSQL_RES* result = mysql_store_result(db);
    if (result) {
      int num_cols = mysql_num_fields(result);
      std::vector<std::string> col_nums(num_cols);
      for (int i=0; i<num_cols; i++) {
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        col_nums[i] = field->name;
      }
      MYSQL_ROW row;
      while ((row = mysql_fetch_row(result))) {
        std::map<std::string, std::string> map;
        for (int i = 0; i < num_cols; i++) {
          if(!row[i]) {
            map.insert(std::make_pair(col_nums[i], "null"));
          } else {
            map.insert(std::make_pair(col_nums[i], row[i]));
          }
        }
        rows->push_back(map);
      }
      mysql_free_result(result);
    } else {
      if (mysql_field_count(db)) {
        success = false;
        break;
      }
    }
    if ((status = mysql_next_result(db)) > 0) {
      success = false;
      break;
    }
  }
  return success;
}

bool Database::Exec(const std::string& sql, std::vector<std::map<std::string, std::string> >* results) {
  MutexLock(db_mutex);
  bool ret = true;
  MYSQL* db = rtb5;
  if (db == NULL) {
    LOG(ERROR) << " No available connection!";
    return false;
  }
  if (mysql_real_query(db, sql.c_str(), sql.length()) >0 && mysql_errno(db)) {
    LOG(ERROR) << "Mysql Query Failed:" << mysql_error(db);
    ret = false;
  } else {
    ret = FetchRows(db, results);
  }
  return ret;
}

std::string Database::GenerateInsertSql(const std::string& table, 
    const std::map<std::string, std::string>& parameters) {
  std::string sql;
  sql += "INSERT INTO `" + table + "` (";
  bool first = true;
  for (const auto& parameter : parameters) {
    if (!first) {
      sql +=  ",";
    } else {
      first = false;
    }
    sql += parameter.first;
  }
  sql += ") VALUES (";
  first = true;
  for (const auto& parameter : parameters) {
    if (!first) {
      sql +=  ",";
    } else {
      first = false;
    }
    sql += "'" + parameter.second + "'";
  }
  sql += ");";
  return sql;
}

bool Database::GenerateParameters(const Click& click, std::string* table, std::map<std::string, std::string>* parameters) {
  *table = "click";
  if (click.click_id() == 0) {
    return false;
  } else {
    (*parameters)["click_id"] = boost::lexical_cast<std::string>(click.click_id());
  }
  (*parameters)["union_id"] = boost::lexical_cast<std::string>(click.union_id());
  (*parameters)["campaign_id"] = boost::lexical_cast<std::string>(click.campaign_id());
  (*parameters)["click_time"] = boost::lexical_cast<std::string>(click.click_time());
  (*parameters)["origin_url"] = click.origin_url();
  (*parameters)["second_jump_url"] = click.second_jump_url();
  (*parameters)["user_id"] = boost::lexical_cast<std::string>(click.user_id());
  (*parameters)["tags"] = click.tags();
  (*parameters)["ip"] = click.ip();
  return true;
}

bool Database::GenerateParameters(const Union& uppper_union, std::string* table, std::map<std::string, std::string>* parameters) {
  *table = "union";
  if (uppper_union.union_id() == 0) {
    return false;
  } else {
    (*parameters)["union_id"] = boost::lexical_cast<std::string>(uppper_union.union_id());
  }
  (*parameters)["union_name"] = uppper_union.union_name();
  (*parameters)["url_pattern"] = uppper_union.url_pattern();
  return true;
}

bool Database::GenerateParameters(const Campaign& campaign, std::string* table, std::map<std::string, std::string>* parameters) {
  *table = "campaign";
  if (campaign.campaign_id() == 0) {
    return false;
  } else {
    (*parameters)["campaign_id"] = boost::lexical_cast<std::string>(campaign.campaign_id());
  }
  (*parameters)["union_id"] = boost::lexical_cast<std::string>(campaign.union_id());
  (*parameters)["campaign_name"] = campaign.campaign_name();
  (*parameters)["pattern"] = campaign.pattern();
  (*parameters)["percent"] = boost::lexical_cast<double>(campaign.percent());
  return true;
}

bool Database::GenerateParameters(const User& user, std::string* table, std::map<std::string, std::string>* parameters) {
  *table = "user";
  if (user.user_id() == 0) {
    return false;
  } else {
    (*parameters)["user_id"] = boost::lexical_cast<std::string>(user.user_id());
  }
  (*parameters)["user_name"] = user.user_name();
  (*parameters)["account"] = user.account();
  (*parameters)["password"] = user.password();
  (*parameters)["token"] = user.token();
  return true;
}

bool Database::GenerateParameters(const Order& order, std::string* table, std::map<std::string, std::string>* parameters) {
  *table = "user";
  if (order.order_id() == 0) {
    return false;
  } else {
    (*parameters)["order_id"] = boost::lexical_cast<std::string>(order.order_id());
  }
  (*parameters)["status"] = boost::lexical_cast<std::string>(order.status());
  (*parameters)["click_id"] = boost::lexical_cast<std::string>(order.click_id());
  (*parameters)["commission"] = boost::lexical_cast<std::string>(order.commission());
  (*parameters)["trading_volume"] = boost::lexical_cast<std::string>(order.trading_volume());
  (*parameters)["order_time"] = boost::lexical_cast<std::string>(order.order_time());
  (*parameters)["valid_time"] = boost::lexical_cast<std::string>(order.valid_time());
  (*parameters)["currency_type"] = order.currency_type();
  return true;
}

bool Database::ParseSqlResult(const std::map<std::string, std::string>& parameters, Union* upper_union) {
  for (const auto& parameter : parameters) {
    if (parameter.first == "union_id") {
      upper_union->set_union_id(boost::lexical_cast<uint64_t>(parameter.second));      
    } else if  (parameter.first == "union_name") {
      upper_union->set_union_name(parameter.second);
    } else if  (parameter.first == "url_pattern") {
      upper_union->set_url_pattern(parameter.second);
    }
  }
  return true;
}

bool Database::ParseSqlResult(const std::map<std::string, std::string>& parameters, Campaign* campaign) {
  for (const auto& parameter : parameters) {
    if (parameter.first == "campaign_id") {
      campaign->set_campaign_id(boost::lexical_cast<uint64_t>(parameter.second));      
    } else if (parameter.first == "campaign_name") {
      campaign->set_campaign_name(parameter.second);      
    } else if (parameter.first == "union_id") {
      campaign->set_union_id(boost::lexical_cast<uint64_t>(parameter.second));      
    } else if  (parameter.first == "pattern") {
      campaign->set_pattern(parameter.second);
    } else if  (parameter.first == "percent") {
      campaign->set_percent(boost::lexical_cast<double>(parameter.second));      
    }
  }
  return true;
}


} // RTB5