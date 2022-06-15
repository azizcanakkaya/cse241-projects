#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////
//Templated Class Point
/////////////////////////////////////////////////////////////////
template<typename T>
class Point{
    public:
        //constructors
        Point();                            //default constructor
        Point(T in_x, T in_y);              //constructor with parameter

        //setters
        void set_x(const T& in_x);          //setting x coordinate
        void set_y(const T& in_y);          //setting y coordinate

        //functions
        void move(T in_x, T in_y);          //moving the coordinate amount of x and y
        void rotate();                      //90 degree rotation

        //getters
        T get_x() const { return x; }       //getting x
        T get_y() const { return y; }       //getting y

    private:
        T x;           //coordinate x
        T y;           //coordinate y    
};

//////////////////////////////////////////////////////////////////
//Functions of the Class Point
//////////////////////////////////////////////////////////////////
template<typename T>
Point<T>::Point() : x(0), y(0) {
    //empty
}

template<typename T>
Point<T>::Point(T in_x, T in_y){
    //setting input parameters
    x = in_x;
    y = in_y;
}

template<typename T>
void Point<T>::set_x(const T& in_x){
    //seeting x
    x = in_x;
}

template<typename T>
void Point<T>::set_y(const T& in_y){
    //setting y
    y = in_y;
} 

template<typename T>
void Point<T>::move(T in_x, T in_y){
    //adding inputs to acoording to the coordinates
    x += in_x;
    y += in_y;
}

template<typename T>
void Point<T>::rotate(){
    //(x,y) will become (y,-x) when rotated 90 degrees
    T temp = -x;
    x = y;
    y = temp;
}
 
/////////////////////////////////////////////////////
//Main Function
/////////////////////////////////////////////////////

int main(){

    //templated array of class
    Point<int> test[3];

    //input parameters
    int x,y;

    //constructor test
    for(int i = 0; i < 3; i++){
        cout << "Test_Class " << i+1 << " : x : " << test[i].get_x() << " y : " << test[i].get_y() << endl;
    }

    //manuplation test
    cout << " Manuplating test_class 1. Enter x , y : ";
    cin >> x >> y;

    test[0].set_x(x);
    test[0].set_y(y);

    cout << "Test_Class 1 : x : " << test[0].get_x() << " y : " << test[0].get_y() << endl;  

    //rotation test
    test[0].rotate();

    cout << "Test_Class 1 : Rotation Test : " << endl
    << "Test_Class 1 : x : " << test[0].get_x() << " y : " << test[0].get_y() << endl;

    return 0;
}