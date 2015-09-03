#!/usr/bin/env python
#coding=utf8
 
import httplib, urllib
 
def GetResponse(params_list,url, suffix):
    httpClient = None
    try:
        params = urllib.urlencode(params_list)
        headers = {"Content-type": "application/x-www-form-urlencoded"
                        , "Accept": "text/plain"}
 
        httpClient = httplib.HTTPConnection(url, 80, timeout=30)
        httpClient.request("POST",  suffix,  params, headers)
 
        response = httpClient.getresponse()
        if (response.status != 200):
            print response.reason
        return response.read()
    except Exception, e:
        print e
    finally:
        if httpClient:
            httpClient.close()

if __name__ == '__main__':
    params_list={'token':'ZhZIC5HluW3vVdlO','begin_date':'2014-01-01','end_date':'2015-08-01'}
    url="union.55haitao.com"
    suffix= "/union.php?mod=api_cashback"
    print GetResponse(params_list,url, suffix)