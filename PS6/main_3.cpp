#include <iostream>

using namespace std;

class Rational{
    public:
        Rational();
        Rational(int num, int denom);
        Rational(int wholeNumber);

        bool operator==(const Rational& obj);
        bool operator<(const Rational& obj);
        bool operator<=(const Rational& obj);
        bool operator>(const Rational& obj);
        bool operator>=(const Rational& obj);
        float operator+(const Rational& obj);
        float operator-(const Rational& obj);
        Rational operator*(const Rational& obj);
        Rational operator/(const Rational& obj);

        friend ostream& operator<<(ostream& out, const Rational& obj);
        friend istream& operator>>(istream& in, Rational& obj);
    
    private:
        int numerator,denominator;
};

Rational::Rational() : numerator(0), denominator(1) {
    //empty
}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    //empty
}

Rational::Rational(int wholeNumber) : numerator(wholeNumber), denominator(1) {
    //empty
}

ostream& operator<<(ostream& out, const Rational& obj){
    out << obj.numerator << "/" << obj.denominator << " ";
}

istream& operator>>(istream& in, Rational& obj){
    in >> obj.numerator >> obj.denominator;
}

bool Rational::operator==(const Rational& obj){
    if( obj.numerator/obj.denominator == numerator/denominator )
        return true;
    else
        return false; 
}

bool Rational::operator<(const Rational& obj){
    if( numerator/denominator < obj.numerator/obj.denominator )
        return true;
    else
        return false;
}

bool Rational::operator<=(const Rational& obj){
    if( numerator/denominator <= obj.numerator/obj.denominator )
        return true;
    else
        return false;
}

bool Rational::operator>(const Rational& obj){
    if( numerator/denominator > obj.numerator/obj.denominator )
        return true;
    else
        return false;
}

bool Rational::operator>=(const Rational& obj){
    if( numerator/denominator >= obj.numerator/obj.denominator )
        return true;
    else
        return false;
}

float Rational::operator+(const Rational& obj){
    float first = numerator/denominator;
    float second = obj.numerator/denominator;
    return (first+second);
}

float Rational::operator-(const Rational& obj){
    float first = numerator/denominator;
    float second = obj.numerator/denominator;
    return (first-second);
}

Rational Rational::operator*(const Rational& obj){
    Rational temp;

    temp.numerator = numerator*obj.numerator;
    temp.denominator = denominator*obj.denominator;

    return temp;
}

Rational Rational::operator/(const Rational& obj){
    Rational temp;

    temp.numerator = numerator*obj.denominator;
    temp.denominator = denominator*obj.numerator;

    return temp;
}

int main(){

    Rational test1;
    Rational test2(4,5);
    Rational test3(9);
    Rational test4;
    Rational test5;

    cout << "Test 1 default constructor : " << test1 << endl
    << "Test 2 consturctor with two parameters : " << test2 << endl
    << "Test 3 constructor with whole number : " << test3 << endl << endl;

    cout << "Enter the values of test 4 : ";
    cin >> test4;

    cout << "Enter the values of test 5 : ";
    cin >> test5;

    cout << endl << "Test 4 output : " << test4 << endl
    << "Test 5 output : " << test5 << endl << endl;

    cout << "Output of Test3 > Test2 : " << (test3 > test2) << endl
    << "Output of Test3 < Test2 : " << (test3 < test2) << endl << endl
    << "Output of Test2 == Test4 : " << (test2 == test4) << endl
    << "Output of Test2 == Test3 : " << (test2 == test3) << endl << endl
    << "Output of Test2 <= Test4 : " << (test2 <= test4) << endl
    << "Output of Test2 >= Test4 : " << (test2 >= test4) << endl << endl
    << "Output of Test2 >= Test3 : " << (test2 >= test3) << endl 
    << "Output of Test2 <= Test3 : " << (test2 <= test3) << endl << endl
    << "Output of Test2 + Test3 : " << (test2 + test3) << endl
    << "Output of Test2 - Test3 : " << (test2 - test3) << endl << endl
    << "Output of Test2 * Test3 : " << (test2 * test3) << endl
    << "Output of Test2 / Test3 : " << (test2 / test3) << endl << endl
    << "Output of Test2 * Test5 : " << (test2 * test5) << endl
    << "Output of Test2 + Test5 : " << (test2 + test5) << endl
    << "Output of Test2 - Test5 : " << (test2 - test5) << endl;



    return 0;
}