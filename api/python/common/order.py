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
  def  InsertDb(self):
    conn = MySQLdb.connect('localhost','root','abcdefg2008','CPSUnion',charset='utf8')
    cur = conn.cursor()
    sql_content = "select * from orders"
    cur.execute(sql_content)
    data = cur.fetchall()
    for i in data:
      print i

if __name__ == '__main__':
  order = Order();
  order.ShowDb();