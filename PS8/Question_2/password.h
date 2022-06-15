#ifndef PASSWORD_H
#define PASSWORD_H
//class definition set
#include <string>
//including needed classes
namespace Authenticate{
    class Password{
        public:
            Password();                //default constructor

            void inputPassword();      //setter for password
            bool isValid();            //validation for password
            std::string getPassword() const; //getter
        private:
            std::string password;
    };

}

#endif