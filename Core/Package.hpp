#ifndef __Package_hpp_2018_06_24_22_54
#define __Package_hpp_2018_06_24_22_54

#include <UUID.hpp>
#include <Version.hpp>
#include <JTime.hpp>

#include <string>

#include <Wrappers.hpp>

using std::string;

struct Resource{
    UUID id;
    std::string uri;
    size_t size;
    unsigned char hash[32];
};

using ErasedResource = PolymorphicWrapper<Resource>;

struct Package:public Resource{
    Version currVersion;
    Instant creationTime;
    Instant updateTime;
    map<std::string,ErasedResource> parts;
};

#endif