#ifndef SECURITY_H
#define SECURITY_H

#include <string>

namespace GTU{
    class Security{
        public:
            //login validation function
            static int validate(std::string username, std::string password);
            //default consturctor
            Security(); 
    };
}

#endif