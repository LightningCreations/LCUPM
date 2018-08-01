#include <Curl.hpp>
#include <utility>

using namespace std::string_literals;

CurlException::CurlException(const std::string& str):srcFunction(str){}
CurlException::CurlException(std::string&& str):srcFunction(str){} 

CurlGlobal::CurlGlobal(){
    if(curl_global_init(CURL_GLOBAL_ALL)!=0){
        throw CurlException("Curl Error thrown (CurlGlobal::{ctor})"s);
    }
}

CurlGlobal::~CurlGlobal(){
    curl_global_cleanup();    
}

void writeF(const void* buff,size_t size,size_t nmemb,OutputStream* strm){
    strm->write(buff,size*nmemb);
}

Curl::Curl(Curl&& r):curl(std::exchange(r.curl,nullptr)),writeTo(std::exchange(r.writeTo,nullptr)){}

Curl::~Curl(){
    if(curl!=nullptr)
        curl_easy_cleanup(curl);
}

Curl::Curl(OutputStream& target):writeTo(&target){
    curl = curl_easy_init();
    if(curl==NULL)
        throw CurlException("Curl Raised Error (Curl::{ctor})");
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,writeTo);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeF);
}

void Curl::setURL(const std::string& url){
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

void Curl::fetch(){
    if(curl_easy_perform(curl)!=0)
        throw CurlException("Curl Raised Error (Curl::fetch)");
}

const char* CurlException::what()const noexcept(true){
    return srcFunction.c_str();
}