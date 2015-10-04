#ifndef SRC_HTTP_CLIENT_H
#define SRC_HTTP_CLIENT_H

#include <string>

namespace RTB5 {

class HttpClient {
 public:
  HttpClient(void);
  ~HttpClient(void);

 public:
  /**
  * @brief HTTP POST请求
  * @param url 输入参数,请求的Url地址,如:http://www.baidu.com
  * @param post 输入参数,使用如下格式para1=val1¶2=val2&…
  * @param response 输出参数,返回的内容
  * @return 返回是否Post成功
  */
  int Post(const std::string& url, const std::string& post, std::string& response);

  /**
  * @brief HTTP GET请求
  * @param url 输入参数,请求的Url地址,如:http://www.baidu.com
  * @param response 输出参数,返回的内容
  * @return 返回是否Post成功
  */
  int Get(const std::string& url, std::string& response);

  /**
  * @brief HTTPS POST请求,无证书版本
  * @param url 输入参数,请求的Url地址,如:https://www.alipay.com
  * @param post 输入参数,使用如下格式para1=val1¶2=val2&…
  * @param response 输出参数,返回的内容
  * @param path 输入参数,为CA证书的路径.如果输入为NULL,则不验证服务器端证书的有效性.
  * @return 返回是否Post成功
  */
  int Posts(const std::string& url, const std::string& post, std::string& response, const char * path = NULL);

  /**
  * @brief HTTPS GET请求,无证书版本
  * @param url 输入参数,请求的Url地址,如:https://www.alipay.com
  * @param response 输出参数,返回的内容
  * @param path 输入参数,为CA证书的路径.如果输入为NULL,则不验证服务器端证书的有效性.
  * @return 返回是否Post成功
  */
  int Gets(const std::string& url, std::string& response, const char * path = NULL);

 public:
  void SetDebug();

 private:
  bool debug;
};

} // RTB5

#endif // SRC_HTTP_CLIENT_H
