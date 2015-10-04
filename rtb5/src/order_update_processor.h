#ifndef SRC_ORDER_UPDATE_PROCESSOR_H
#define SRC_ORDER_UPDATE_PROCESSOR_H

#include <string>
#include <boost/functional/hash.hpp>
#include "src/database.h"
#include "src/order_update_functor.h"
#include "src/haitao55_order_update_functor.h"

namespace RTB5 {

class OrderUpdateProcessor {
 public:
  //
  ~OrderUpdateProcessor ();
  //
  bool Init();
  //
  bool Process(std::vector<Order>* orders);

 private:


 private:
  //
  std::vector<OrderUpdateFunctor*> functors;
  //
  Database database;
};

} // RTB5

#endif // SRC_ORDER_UPDATE_PROCESSOR_H
