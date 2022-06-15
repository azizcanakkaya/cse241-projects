#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////
//MyInteger Class
/////////////////////////////////////////////////////////////////

class PrimeNumber{
    public:
        //constructors
        PrimeNumber();                                      //Default Constructors
        PrimeNumber(int input);                             //Constructors with parameter

        int get_prime_num() const { return prime_num; }     //Getter for prime number
    
        //Operator overlaoding
        PrimeNumber operator--( int );                      //Decrease operator overloading
        PrimeNumber operator++( int );                      //Increase operator overloading

    private:
        int prime_num;                                      //prime number data
};

/////////////////////////////////////////////////////////////////
//MyInteger Class
/////////////////////////////////////////////////////////////////

PrimeNumber::PrimeNumber() : prime_num(1){
    //empty
}

PrimeNumber::PrimeNumber(int input) : prime_num(input){
    //setting counter for divider counter
    int counter = 0;
    //starting from the prime number checking if it is divided or not in a decreasing manner
    for( int i = prime_num; i > 0; i-- ){
        if( prime_num % i == 0)
            counter++;
        }
        //if divider count is greater than 2 setting the prime number to 1
        if( counter != 2 )
            prime_num = 1;
}

PrimeNumber PrimeNumber::operator++( int ){
     //setting counter for divider counter
    int counter = 0;
    //starting from the prime number checking if it is divided or not in a increasing manner
    while( prime_num++ ){
        for( int i = prime_num; i > 0; i-- ){
            if( prime_num % i == 0)
                counter++;
        }
        //checking if the number is a prime number or not with the divider counter
        if( counter == 2 )
            break;
        else
            counter = 0;
    }
    //creating temporary prime number class
    PrimeNumber temp(prime_num);
    //return the temporary class
    return temp;
}

PrimeNumber PrimeNumber::operator--( int ){
    //setting counter for divider counter
    int counter = 0;
    //starting from the prime number checking if it is divided or not in a decreasing manner
    while( prime_num-- ){
        for( int i = prime_num; i > 0; i-- ){
            if( prime_num % i == 0)
                counter++;
        }
        //checking if the number is a prime number or not with the divider counter
        if( counter == 2 )
            break;
        else
            counter = 0;
    }
    //creating temporary prime number class
    PrimeNumber temp(prime_num);
    //return the temporary class
    return temp;
}

/////////////////////////////////////////////////////////////////
//Main Function
/////////////////////////////////////////////////////////////////

int main() {

    PrimeNumber test;
    PrimeNumber test1;
    PrimeNumber test2(3);
    PrimeNumber test3(4);

    cout << "Test for Constructor with input of 3 : "; 
    cout << test2.get_prime_num() << endl << endl;
    cout << endl;
    
    cout << "Test for Constructor with input of 4 : "; 
    cout << test3.get_prime_num() << endl << endl;
    cout << endl;

    cout << "Default Constructor : "
    << test.get_prime_num() << endl << endl;

    test++;

    cout << "Increasing Default Constructor : "
    << test.get_prime_num() << endl << endl;
 
    test++;

    cout << "Increasing Default Constructor : "
    << test.get_prime_num() << endl << endl;

    test++;

    cout << "Increasing Default Constructor : "
    << test.get_prime_num() << endl << endl;

    test--;

    cout << "Decreasing Default Constructor : "
    << test.get_prime_num() << endl << endl;

    test--;

    cout << "Decreasing Default Constructor : "
    << test.get_prime_num() << endl << endl;

    return 0;
}