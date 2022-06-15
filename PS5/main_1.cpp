#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////
//Vector2D Class
/////////////////////////////////////////////////////////////////

class Vector2D{
    public:
        //constructors
        Vector2D();                                     //Default Constructor
        Vector2D(int in_x, int in_y);                   //Constructor with parameters
        //setters
        void set_x(const int in_x);                     //setter for x point
        void set_y(const int in_y);                     //setter for y point
        //getters           
        int get_x() const { return x; }                 //returning x point
        int get_y() const { return y; }                 //retruning y point
        //operators
        Vector2D operator*( const Vector2D& obj );      //multiply operator overload

    private://data
        int x;
        int y;
};

//////////////////////////////////////////////////////////////////
//Functions of the class Vector2D
//////////////////////////////////////////////////////////////////

Vector2D::Vector2D() : x(0), y(0) {
    //empty
}

Vector2D::Vector2D(int in_x, int in_y) : x(in_x), y(in_y){
    //empty
}

void Vector2D::set_x(const int in_x){
    x = in_x;     //setting x
}

void Vector2D::set_y(const int in_y){
    y = in_y;    //setting y
}

Vector2D Vector2D::operator*(const Vector2D& obj){
    //temporary class for returning
    Vector2D temp;
    //multiplying datas with each other
    temp.x = x * obj.get_x();
    temp.y = y * obj.get_y();
    //returning default value
    return temp;
}

/////////////////////////////////////////////////////////////////////
//Main Function
/////////////////////////////////////////////////////////////////////

int main(){

    Vector2D test;
    Vector2D test1(4,5);
    Vector2D test2(8,2);
    Vector2D test3(-5,3);

    cout << "Default Constructor test : " << endl
    << "x : " << test.get_x() << " y : " << test.get_y() << endl;

    cout << "Test1 : " << endl
    << "x : " << test1.get_x() << " y : " << test1.get_y() << endl;

    cout << "Test2 : " << endl
    << "x : " << test2.get_x() << " y : " << test2.get_y() << endl;

    cout << "Test3 : " << endl
    << "x : " << test3.get_x() << " y : " << test3.get_y() << endl;

    Vector2D test4 = test*test1;

    cout << "Test1*Default : " << endl
    << "x : " << test4.get_x() << " y : " << test4.get_y() << endl;    

    test4 = test1*test2;

    cout << "Test1*Test2 : " << endl
    << "x : " << test4.get_x() << " y : " << test4.get_y() << endl;

    test4 = test1*test3;

    cout << "Test1*Test3 : " << endl
    << "x : " << test4.get_x() << " y : " << test4.get_y() << endl; 

    return 0;
}