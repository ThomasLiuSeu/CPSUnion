#!/usr/bin/env python
#coding=utf8
import MySQLdb
class Order(object):
  def  ShowDb(self):
    conn = MySQLdb.connect('localhost','root','abcdefg2008','CPSUnion',charset='utf8')
    cur = conn.cursor()
    sql_content = "select * from orders"
    cur.execute(sql_content)
    data = cur.fetchall()
    for i in data:
      print i

  def  InsertDb(self, order_id, click_id, upper_union_id, store_id, store_name, trading_volume, cashback, order_time, report_time, valid_time, currency_type, status):
    conn = MySQLdb.connect('localhost','root','abcdefg2008','CPSUnion',charset='utf8')
    cur = conn.cursor()
    sql_content = "INSERT INTO `orders`  values(" + bytes(order_id) + "," + bytes(click_id) + "," + bytes(upper_union_id) + "," + bytes(store_id) + ",\"" + store_name + "\"," + bytes(float(trading_volume) *100)+ ","  + bytes(float(cashback)*100) + "," + bytes(order_time) + "," + bytes(report_time)+ "," + bytes(valid_time) + ", \"" + currency_type  +"\"," + bytes(status )+ " );";
    print sql_content;
    cur.execute(sql_content)
    conn.commit()
    data = cur.fetchall()
    for i in data:
      print i

if __name__ == '__main__':
  order = Order();
  order.ShowDb();