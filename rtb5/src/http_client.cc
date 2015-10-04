#include "src/http_client.h"
#include <string>
#include <curl/curl.h>

namespace RTB5 {

HttpClient::HttpClient(void) : debug(false) {

}

HttpClient::~HttpClient(void) {

}

static int OnDebug(CURL *, curl_infotype itype, char * data, size_t size, void *) {
  if(itype == CURLINFO_TEXT)
  {
    printf("[TEXT]%s\n", data);
  }
  else if(itype == CURLINFO_HEADER_IN)
  {
    printf("[HEADER_IN]%s\n", data);
  }
  else if(itype == CURLINFO_HEADER_OUT)
  {
    printf("[HEADER_OUT]%s\n", data);
  }
  else if(itype == CURLINFO_DATA_IN)
  {
    printf("[DATA_IN]%s\n", data);
  }
  else if(itype == CURLINFO_DATA_OUT)
  {
    printf("[DATA_OUT]%s\n", data);
  }
  return 0;
}

static size_t OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid) {
  std::string* str = dynamic_cast<std::string*>((std::string *)lpVoid);
  if( NULL == str || NULL == buffer ) {
    return -1;
  }

  char* data = (char*)buffer;
  str->append(data, size * nmemb);
  return nmemb;
}

int HttpClient::Post(const std::string& url, const std::string& post, std::string& response) {
  CURLcode res;
  CURL* curl = curl_easy_init();
  if(NULL == curl) {
    return CURLE_FAILED_INIT;
  }
  if(debug) {
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
  }
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 1);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
  curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  return res;
}

int HttpClient::Get(const std::string& url, std::string& response) {
  CURLcode res;
  CURL* curl = curl_easy_init();
  if(NULL == curl) {
    return CURLE_FAILED_INIT;
  }
  if(debug) {
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
  }
  curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
  /**
  * 当多个线程都使用超时处理的时候，同时主线程中有sleep或是wait等操作。
  * 如果不设置这个选项，libcurl将会发信号打断这个wait从而导致程序退出。
  */
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  return res;
}

int HttpClient::Posts(const std::string& url, const std::string& post, std::string& response, const char * path) {
  CURLcode res;
  CURL* curl = curl_easy_init();
  if(NULL == curl) {
    return CURLE_FAILED_INIT;
  }
  if(debug) {
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
  }
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_POST, 1);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
  curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
  if(NULL == path) {
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
  } else {
    //缺省情况就是PEM，所以无需设置，另外支持DER
    //curl_easy_setopt(curl,CURLOPT_SSLCERTTYPE,"PEM");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(curl, CURLOPT_CAINFO, path);
  }
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  return res;
}

int HttpClient::Gets(const std::string& url, std::string& response, const char * path) {
  CURLcode res;
  CURL* curl = curl_easy_init();
  if(NULL == curl) {
    return CURLE_FAILED_INIT;
  }
  if(debug) {
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
  }
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
  if(NULL == path) {
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
  } else {
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(curl, CURLOPT_CAINFO, path);
  }
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void HttpClient::SetDebug() {
  debug = true;
}

} // RTB5
