
#include "src/haitao55_order_update_functor.h"
#include <time.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <glog/logging.h>

namespace RTB5 {

bool Haitao55OrderUpdateFunctor::Init() {
  return true;
}

bool Haitao55OrderUpdateFunctor::Process(std::vector<Order>* orders) {
  std::string url = "union.55haitao.com/union.php?mod=api_cashback";
  std::string post = "token=ZhZIC5HluW3vVdlO&begin_date=2014-01-01&end_date=2016-10-01";
  std::string response;
  if (http_client.Post(url, post, response) != 0) {
    LOG(ERROR) << "Post Failed:" << url;
  }
  LOG(ERROR) << "response" << response;
  return true;
}

} // RTB5