#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////
//Class Pizza
/////////////////////////////////////////////////////////////////
class Pizza{
    public:
        //default constructor
        Pizza();
        //constructor with parameters
        Pizza(string sz, string typ, string tp_typ, int tp_tt);

        //price computation function
        void computePrice();
        //Description display function
        void outputDescription();

    private:
        int size;               //size parameter 
        int type;               //type parameter
        int topping_total;      //number of toppings
        int topping_type;       //topping parameter
        int price;              //price of the pizza
};

Pizza::Pizza() : size(0), type(0), topping_total(0), topping_type(0), price(0) {
    //empty
}

Pizza::Pizza(string sz, string typ, string tp_typ, int tp_tt){
    
    //comparing size input and picking the size parameter
    if( sz == "small" )
        size = 1;
    else if( sz == "medium" )
        size = 2;
    else if( sz == "large" )
        size = 3;
    else
        size = 0;

    //////////////////////////////////////////////////////
    //comparing type input and picking the type parameter
    if( typ == "deep fish" )
        type = 1;
    else if( typ == "hand tossed" )
        type = 2;
    else if( typ == "pan" )
        type = 3;
    else
        type = 0; 


    //////////////////////////////////////////////////////
    //comparing topping_type input and picking the topping_type parameter
    if( tp_typ == "pepperoni" )
        topping_type = 1;
    else if( tp_typ == "cheese" )
        topping_type = 2;
    else
        topping_type = 0;

    //topping amount set
    topping_total = tp_tt;

    //computing price
    computePrice();
}

//////////////////////////////////////////////////////////////////
//Functions of the Class Pizza
//////////////////////////////////////////////////////////////////
void Pizza::computePrice(){
    //computing price according to the size of pizza
    if( size == 1 )
        price = 10 + ( topping_total*2 );
    else if( size == 2 )
        price = 14 + ( topping_total*2 );
    else if( size == 3 )
        price = 17 + ( topping_total*2 );
    else
        price = 0;
}

void Pizza::outputDescription(){
    
    //output for size
    if( size == 1 )
        cout << "Size : Small " << endl;
    else if( size == 2 )
        cout << "Size : Medium " << endl;
    else if( size == 3 )
        cout << "Size : Large " << endl;
    else
        cout << "Invalid size!" << endl;

    //////////////////////////////////////////////////////
    //output for type
    if( type == 1 )
        cout << "Type : Deep Fish " << endl;
    else if( type == 2 )
        cout << "Type: Hand Tossed " << endl;
    else if( type == 3 )
        cout << "Type: Pan" << endl;
    else
        cout << "Invalid type!" << endl;


    //////////////////////////////////////////////////////
    //output for topping_type
    if( topping_type == 1 )
        cout << "Topping Type : Pepperoni " << endl;
    else if( topping_type == 2 )
        cout << "Topping Type : Cheese " << endl;
    else
        cout << "Invalid topping type!" << endl;

    //output of price
    cout << "Price : " << price << "$" <<endl;
}

//////////////////////////////////////////////////////////////////
//Main Function
//////////////////////////////////////////////////////////////////
int main(){

    //test1
    Pizza small("small", "pan", "cheese", 3);
    small.outputDescription();
    cout << endl;

    //test2
    Pizza medium("medium","deep fish","pepperoni",2);
    medium.outputDescription();
    cout << endl;

    //test3
    Pizza lagre("large","hand tossed","cheese",1);
    lagre.outputDescription();
    cout << endl;

    //test4
    Pizza error;
    error.outputDescription();
    cout << endl;
    
    return 0;
}