#!/usr/bin/env python
#coding=utf8
import json
import sys; 
sys.path.append("/var/www/html/CPSUnion/api/python/common") 
from httpclient import GetResponse
from order import Order

class FiftyFiveOrder(Order):
  def __init__(self):
    params_list={'token':'ZhZIC5HluW3vVdlO','begin_date':'2014-01-01','end_date':'2015-08-01'}
    url="union.55haitao.com"
    suffix= "/union.php?mod=api_cashback"
    data = GetResponse(params_list,url, suffix)
    print data

if __name__ == '__main__':
  order = FiftyFiveOrder();
  order.ShowDb();