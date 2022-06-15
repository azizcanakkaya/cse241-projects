#include <iostream>
#include "Security.h"
#include "Administrator.h"
#include "User.h"
#include <string>

using namespace std;

using namespace GTU;

int main(){
    //object set
    User usr;
    Administrator admin;
    //input set
    string pass,username;
    //getting inputs for admin
    cout << " Enter admin username and password : ";
    cin >> username >> pass;
    //admin test output
    cout << " Validation : " << admin.Login(username,pass) << endl << endl;
    //getting input for user
    cout << " Enter user username and password : ";
    cin >> username >> pass;
    //user test output
    cout << " Validation : " << usr.Login(username,pass) << endl << endl;

    return 0;
}