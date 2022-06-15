#include "password.h"
#include "user.h"
#include <iostream>
//including libraries and set up of namespaces
using namespace std;
using namespace Authenticate;

int main(){
    //object creation for tests
    User test1;
    Password test2;
    //user test for input
    test1.inputUserName();
    //comparing input and output
    cout << "Input : " << test1.getUserName() << endl << endl;
    //password test for input
    test2.inputPassword();
    //comparation for result
    cout << "Input : " << test2.getPassword() << endl;

    return 0;
}