#!/usr/bin/env python
#coding=utf8
import json
import sys; 
sys.path.append("/var/www/html/CPSUnion/api/python/common") 
from httpclient import GetResponse
from order import Order
import time

class FiftyFiveOrder():
  def __init__(self):
    params_list={'token':'ZhZIC5HluW3vVdlO','begin_date':'2014-01-01','end_date':'2015-10-01'}
    url="union.55haitao.com"
    suffix= "/union.php?mod=api_cashback"
    data = GetResponse(params_list,url, suffix)
    print  data;
    decodejson  = json.loads(data)
    if decodejson["status"]["code"] == 0 :
      orders_data = decodejson["data"]
      for order_data in orders_data:
        print order_data;
        order = Order();
        order.InsertDb(order_data["order_id"], order_data["tagcode"], 1, order_data["store_id"], order_data["store_name"], order_data["sale_amount"], order_data["cashback"], order_data["order_time"], order_data["report_time"], order_data["valid_time"], order_data["currency_type"],  order_data["status"]);
        order.ShowDb();
    else :
      print decodejson["status"]

if __name__ == '__main__':
  fiftyfiveorder = FiftyFiveOrder();
