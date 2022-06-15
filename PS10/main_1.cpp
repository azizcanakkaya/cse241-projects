#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
        Person();
        Person(string theName);
        Person(const Person& theObject);
        string getName() const;
        Person& operator=(const Person& rtSide);
        friend istream& operator>>(istream& inStream, Person& personObject);
        friend ostream& operator<<(ostream& outStream, const Person& personObject);
    private:
        string name;
};

class Vehicle{
    public:
        Vehicle();
        Vehicle(const Vehicle& obj);
        void setName(string nm);
        void setCylinder(int input);
        void setOwner(const Person& obj);

        string getName() const { return name; }
        int getCylinder() const { return cylinders; }
        Person getOwner() const { return owner; }

    private:
        string name;
        int cylinders;
        Person owner;
};

class Truck : public Vehicle{
    public:
        void setCap(double input);
        double getCap() const { return capacity; }
        Truck();
        Truck(const Truck& obj);
        Truck operator=(const Truck& obj);
    private:
        double capacity;
};

Person::Person(){
    name  = "-";
}

Person::Person(string theName){
    name  = theName;
}

Person& Person::operator=(const Person& rtSide){
    this->name = rtSide.getName();

    return *this;
}

string Person::getName() const{
    return name;
}

Person::Person(const Person& theObject){
    *this = theObject;
}

istream& operator>>(istream& inStream, Person& personObject){
    inStream >> personObject.name;
}

ostream& operator<<(ostream& outStream, const Person& personObject){
    outStream << personObject.name;
}

Vehicle::Vehicle() : name("-"), cylinders(0) {
    //empty
}

Vehicle::Vehicle(const Vehicle& obj){
    this->name = obj.name;
    this->cylinders = obj.cylinders;
    this->owner = obj.owner;
}

void Vehicle::setName(string nm){
    name = nm;
}

void Vehicle::setCylinder(int input){
    cylinders = input;
}

void Vehicle::setOwner(const Person& obj){
    this->owner = obj;
}

void Truck::setCap(double input){
    capacity = input;
}

Truck::Truck() : capacity(0) {
    //empty
}

Truck::Truck(const Truck& obj){
    *this = obj;
}
Truck Truck::operator=(const Truck& obj){
    this->capacity = obj.capacity;

    this->setName( obj.getName() );
    this->setOwner( obj.getOwner() );
    this->setCylinder( obj.getCylinder() );

    return *this;
}

int main(){

    Vehicle test1;

    Truck test2;

    Person test;
    string brand_name;
    double capacity;
    int cylinders;

    cout << "Test for default vehicle : " << endl
    << "Cylinders : " << test1.getCylinder() << " , Name : " << test1.getName() << " , Owner : " << test1.getOwner() << endl; 
    
    cout << "Test for default truck : " << endl
    << "Cylinders : " << test2.getCylinder() << " , Name : " << test2.getName() << " , Owner : " << test2.getOwner() << " , Capacity : " << test2.getCap() << endl << endl;

    cout << "Enter values for truck such as : capacity, owner, brandname, cylinders : ";

    cin >> capacity >> test >> brand_name >> cylinders;

    cout << "Output test for person : " << test << endl << endl;

    test2.setCap(capacity);
    test2.setCylinder(cylinders);
    test2.setName(brand_name);
    test2.setOwner(test);

    cout << "Test for default truck : " << endl
    << "Cylinders : " << test2.getCylinder() << " , Name : " << test2.getName() << " , Owner : " << test2.getOwner() << " , Capacity : " << test2.getCap() << endl;

    return 0;
}