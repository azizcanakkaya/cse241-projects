#include <iostream>

using namespace std;

int fibonacci(int fn){
    if( fn <= 1 )
        return 1;
    else
        return fibonacci(fn-1) + fibonacci(fn-2);
}


int main(){

    int input;
    while(1){
        cout << "Enter which n th fibonacci to see : ";
        cin >> input;
        cout << input << " th number : " << fibonacci(input) << endl << endl;
    }

    return 0;
}