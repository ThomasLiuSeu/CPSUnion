#!/usr/bin/env python
#coding=utf8
 
import httplib, urllib
 
def GetResponse(params_list,url, suffix):
    httpclient = None
    try:
        params = urllib.urlencode(params_list)
        headers = {"Content-type": "application/x-www-form-urlencoded"
                        , "Accept": "text/plain"}
 
        httpclient = httplib.HTTPConnection(url, 80, timeout=30)
        httpclient.request("POST",  suffix,  params, headers)
        print params; 
        response = httpclient.getresponse()
        if (response.status != 200):
            print response.reason
        return response.read()
    except Exception, e:
        print e
    finally:
        if httpclient:
            httpclient.close()

if __name__ == '__main__':
    params_list={'token':'ZhZIC5HluW3vVdlO','begin_date':'2014-01-01','end_date':'2015-10-01'}
    url="union.55haitao.com"
    suffix= "/union.php?mod=api_cashback"
    print GetResponse(params_list,url, suffix)
