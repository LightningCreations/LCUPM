#include <Curl.hpp>
#include <utility>

CurlGlobal::CurlGlobal(){
    curl_global_init(CURL_GLOBAL_ALL);
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
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,writeTo);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeF);
}

void Curl::setURL(const std::string& url){
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

CURLcode Curl::fetch(){
    return curl_easy_perform(curl);
}