#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/////////////////////////////////////////////////////////////////
//MyInteger Class
/////////////////////////////////////////////////////////////////

class MyInteger{
    public:
        //Constructor      
        MyInteger();                                //Default Constructor
        MyInteger(string input);                    //Constructor 
        //Functions
        void transfer(char in[]);                   //transfering character array to an array of integer digits
        void sort();                                //sorting array in ascending manner
        //getter and setter
        int get_value() const { return value; }     //getting the value
        void set_value(string input);               //setting value and digits array
        //operator overloading
        int operator[](int index);                  //index return

    private:
        int value;      //integer
        int *digits;    //digits of integer
        int size;       //number of digits
};

/////////////////////////////////////////////////////////////////
//Functions of the MyInteger class
/////////////////////////////////////////////////////////////////

MyInteger::MyInteger(string input){
    //setting the value and required parameters
    set_value(input);
}

MyInteger::MyInteger(){
    //setting the default parameters
    char in[] = {'0'};
    //transfering and setting parameters
    transfer(in);
}

void MyInteger::transfer(char in[]){
    //setting digits array
    digits = new int[ size ];
    //setting value
    value = stoi(in);
    //turning characters to integers for digits array
    for(int i = 0; i < size; i++)
        digits[i] = in[i] - '0';
    //sorting the array in an ascending manner
    sort();
}

void MyInteger::set_value(string input){
    //setting size and char array
    size = input.length();
    char in[size];
    //copying string to character array
    strcpy(in,input.c_str());
    //setting private values
    transfer(in);
}

int MyInteger::operator[](int index){
    //checking index parameter for required conditions
    if( index > size || index < 0 )
        return -1;              //return -1 if it is out of index bound
    else
        return digits[index];   //returning digit if it is in the bound of indexs
}

void MyInteger::sort(){
    //temporary integer
    int temp;
    //bubble sort algorithm
     for(int i = 0; i < size; i++ ){

        for(int j = i + 1; j < size; j++ ){
            //if the digit greater than the next digit, changing them with using temp definition
            if( digits[j] < digits[i] ){
                temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////
//Main Function
/////////////////////////////////////////////////////////////////


int main(){

    string input;
    int i = 0,input_index;

    cout << "Enter the numbers : ";
    getline(cin,input);

    MyInteger test(input);

    while( i < 5 ){

        cout << "Enter the index : ";
        cin >> input_index;
        cout << " Test " << i << ", index " << input_index << " : " << test[input_index] << endl << endl;
        i++;
    }

    return 0;

}