#ifndef __Curl_hpp_2018_07_27_22_34
#define __Curl_hpp_2018_07_27_22_34
#include <curl/curl.h>
#include <IOWrapper.hpp>
#include <string>
#include <stdexcept>

class CurlException:public std::exception{
    std::string srcFunction;
public:
    CurlException(const std::string&);
    CurlException(std::string&&);
    const char* what()const noexcept(true);
};

class CurlGlobal{
    CurlGlobal(const CurlGlobal&)=delete;
    CurlGlobal(CurlGlobal&&)=delete;
    CurlGlobal& operator=(const CurlGlobal&)=delete;
    CurlGlobal& operator=(CurlGlobal&&)=delete;
public:
    CurlGlobal();
    ~CurlGlobal();
};

class Curl{
private:
    OutputStream* writeTo;
    CURL* curl;
    char buff[CURL_ERROR_SIZE];
    Curl(const Curl&)=delete;
    Curl& operator=(const Curl&)=delete;
    Curl& operator=(Curl&&)=delete;
public:
    Curl(Curl&&);
    Curl(OutputStream&);
    ~Curl();
    void setURL(const char*);
    void fetch();
};

#endif