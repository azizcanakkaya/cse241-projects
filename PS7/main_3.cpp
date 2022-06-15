#include <iostream>

using namespace std;

class Polynomial{
    public:
        Polynomial();
        Polynomial(double cf[],int size);
        ~Polynomial();

        void print();

        Polynomial operator=(const Polynomial& obj);
        Polynomial operator+(const Polynomial& obj);
        Polynomial operator+(double cf);
        Polynomial operator*(const Polynomial& obj);
        Polynomial operator*(double cf);
        Polynomial operator-(const Polynomial& obj);
        Polynomial operator-(double cf);

    private:
        double *coef;
        int order;
};

Polynomial::Polynomial() : order(0){
    //empty
}

Polynomial::Polynomial(double cf[],int size){
    order = size;
    coef = new double[order];
    
    for(int i = 0; i < order; i++)
        coef[i] = cf[i];
}

Polynomial::~Polynomial(){
    if( order != 0 )
        delete []coef;
}

Polynomial Polynomial::operator=(const Polynomial& obj){
    Polynomial temp;

    temp.order = obj.order;

    temp.coef = new double[obj.order]; 

    for(int i = 0; i < obj.order; i++)
        temp.coef[i] = obj.coef[i];

    return temp;
}

Polynomial Polynomial::operator+(const Polynomial& obj){
    Polynomial temp;

    if( order > obj.order ){
        temp.order = order;

        temp.coef = new double[order]; 

        for( int i = 0; i < order; i++)
            temp.coef[i] = coef[i];

        for(int i = 0; i < obj.order; i++)
            temp.coef[i] += obj.coef[i];
    }

    else if( order < obj.order ){
        temp.order = obj.order;

        temp.coef = new double[obj.order]; 

        for( int i = 0; i < obj.order; i++)
            temp.coef[i] = obj.coef[i];

        for(int i = 0; i < order; i++)
            temp.coef[i] += coef[i];
    }
    else{
        temp.order = order;

        temp.coef = new double[order]; 

        for( int i = 0; i < order; i++)
            temp.coef[i] = obj.coef[i] + coef[i];
    }

    return temp;
}

Polynomial Polynomial::operator-(const Polynomial& obj){
    Polynomial temp;

    if( order > obj.order ){
        temp.order = order;

        temp.coef = new double[order]; 

        for( int i = 0; i < order; i++)
            temp.coef[i] = coef[i];

        for(int i = 0; i < obj.order; i++)
            temp.coef[i] -= obj.coef[i];
    }

    else if( order < obj.order ){
        temp.order = obj.order;

        temp.coef = new double[obj.order]; 

        for( int i = 0; i < obj.order; i++)
            temp.coef[i] = obj.coef[i];

        for(int i = 0; i < order; i++)
            temp.coef[i] -= coef[i];
    }
    else{
        temp.order = order;

        temp.coef = new double[order]; 

        for( int i = 0; i < order; i++)
            temp.coef[i] = obj.coef[i] - coef[i];
    }
    return temp;
}


Polynomial Polynomial::operator+(double cf){
    this->coef[0] += cf;  
    return *this;
}

Polynomial Polynomial::operator-(double cf){
    this->coef[0] -=cf;
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& obj){
    this->order = this->order*obj.order;

    double *temp;
    temp = new double[this->order];

    for(int i = 0; i < this->order; i++ ){
        for(int j = 0; j < obj.order; j++)
            temp[i*j] = this->coef[i] * obj.coef[j];
    }
    
    delete this->coef;

    this->coef = new double[this->order];

    for(int i = 0; i <this->order; i++)
        this->coef[i] = temp[i];

    return *this;
}

Polynomial Polynomial::operator*(double cf){
    for(int i = 0; i < this->order; i++)
        this->coef[i] = this->coef[i] * cf;

    return *this;    
}

void Polynomial::print(){
    for(int i = 0; i < order; i++)
        cout << " x^" << i << "*" << coef[i] << " +";
}

int main(){

    Polynomial test1;

    double input1[] = {0.2,1.4,5.6};
    double input2[] = {2,6,4,5.6,2.1};

    Polynomial test2(input1,3);
    Polynomial test3(input2,5);

    cout << " Test 2 : ";
    test2.print();
    cout << endl << endl;

    cout << " Test 3 : ";
    test3.print();
    cout << endl << endl;

    test3*test2;
    cout << " Test 3 * Test 2 : "; 
    test3.print();
    cout << endl << endl;

    test3*2;
    cout << " Test 3 * 2 : "; 
    test3.print();
    cout << endl << endl;
    
    test3 - 2;
    cout << " Test 3 - 2 : "; 
    test3.print();
    cout << endl << endl;

    test3 - test2;
    cout << " Test 3 - test2 : "; 
    test3.print();
    cout << endl << endl;

    test3 + test2;
    cout << " Test 3 + 2 : "; 
    test3.print();
    cout << endl << endl;

    return 0;
}