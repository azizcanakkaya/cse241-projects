#include <iostream>

using namespace std;

class Complex{
    public:
        Complex();
        Complex(double a, double b);
        Complex(double realPart);

        bool operator==(const Complex& obj);
        Complex operator+(const Complex& obj);
        Complex operator-(const Complex& obj);
        Complex operator*(const Complex& obj);
        
        friend ostream &operator<<(ostream &out, const Complex& obj);
        friend istream &operator>>(istream &in, Complex& obj);

    private:
        double imaginary,real;
}const i(0,1);

Complex::Complex() : imaginary(0), real(0) {
    //empty
}

Complex::Complex(double a, double b) : imaginary(b), real(a) {
    //empty
}

Complex::Complex(double realPart) : real(realPart), imaginary(0) {
    //empty    
}

bool Complex::operator==(const Complex& obj){
    if( real == obj.real && imaginary == obj.imaginary )
        return true;
    else
        return false;
}

Complex Complex::operator+(const Complex& obj){
    Complex temp;
    
    temp.real = real + obj.real;
    temp.imaginary = imaginary + obj.imaginary;

    return temp;
}

Complex Complex::operator-(const Complex& obj){
    Complex temp;

    temp.real = real - obj.real;
    temp.imaginary = imaginary - obj.imaginary;

    return temp;
}

Complex Complex::operator*(const Complex& obj){
    Complex temp;

    temp.real = real * obj.real;
    temp.imaginary = imaginary * obj.imaginary;

    return temp; 
}

ostream& operator<<(ostream &out, const Complex& obj){
    cout << obj.real << " + " << obj.imaginary << "i "; 
}

istream& operator>>(istream &in, Complex& obj){
    in >> obj.real >> obj.imaginary;
}

int main(){

    Complex a(2,8);
    Complex b(4,5);
    Complex c(2.4);
    Complex d;
    Complex test;

    cout << "Enter the values of d : ";
    cin >> d;

    cout << endl << "Output default constructor : " << test << endl
    << "Output of a (constructor with two parameters) : " << a << endl
    << "Output of b (constructor with two parameters) : " << b << endl
    << "Output of c (constructor with realPart parameter) : " << c << endl
    << "Output of d : " << d << endl << endl
    << "Output of ( a + b ) : " << (a + b) << endl
    << "Output of  ( a - b ) : " <<  (a - b) << endl
    << "Output of ( a * b ) : " << (a * b) << endl
    << "Output of ( b == d ) : " << (b == d) << endl
    << "Output of ( b == c ) : " << (b == c) << endl; 


    return 0;
}