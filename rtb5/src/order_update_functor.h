#ifndef SRC_ORDER_UPDATE_FUNCTOR_H
#define SRC_ORDER_UPDATE_FUNCTOR_H

#include <string>
#include <vector>
#include "src/http_client.h"
#include "proto/order.pb.h"

namespace RTB5 {

class OrderUpdateFunctor {
 public:
  //
  virtual bool Init() {
    return true;
  }
  //
  virtual bool Process(std::vector<Order>* orders) {
    return true;
  }
  //
  virtual std::string Name() {
    return "";
  }
  //
  virtual ~OrderUpdateFunctor() {}

 private:
  //
  uint64_t GenerateOrderID(const Order& order) {
    return (order.click_id() & 0xFFFF000000000000) + ((order.order_time() & 0xFFFFFFFF) << 16) + (order.click_id() & 0xFFFF);
  }

 public:
  //
  HttpClient http_client;
};

} // RTB5

#endif // SRC_ORDER_UPDATE_FUNCTOR_H
