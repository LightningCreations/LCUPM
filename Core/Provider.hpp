#ifndef __Provider_hpp_2018_06_24_23_59
#define __Provider_hpp_2018_06_24_23_59
#include <string>
#include <vector>
#include <UUID.hpp>

using std::string;
using std::vector;
namespace lcpm{
   namespace core{ 
        struct RSAPublicKey{
            size_t size;
            uint64_t encExponent;
            unsigned char key[256];
        };


        class Provider{
        private:
            UUID id;
            RSAPublicKey key;
            string name;
        public:
            Provider();
            Provider(const RSAPublicKey&,const string& name);
            Provider(const RSAPublicKey&,string&& name);
            Provider(RSAPublicKey&&,const string& name);
            Provider(RSAPublicKey&&,string&&);
            const RSAPublicKey& getKey()const;
            const string& getName()const;
            const UUID& getUUID()const;
        };

        class ProviderList{
        private:
            map<UUID,Provider> providers;
        public:
            ProviderList();

        };
    }
}

#endif