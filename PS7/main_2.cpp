#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        Student();
        ~Student();

        void setName(string nm);
        void setClasses(string cls[],int size);
        string getName() const;
        string* getclassList() const;
        int getnumClasses() const;

        Student operator=(const Student& obj);
        void user_input();
        void listclasses();
        void reset();

    private:
        string name;
        int numClasses;
        string *classList;
};

Student::Student(): name("--"), numClasses(0){
    //empty
}

Student::~Student(){
    if( numClasses != 0 )
        delete []classList;
}

void Student::setName(string nm){
    name = nm;
}

void Student::setClasses(string cls[], int size){
    numClasses = size;
    classList = new string[size];

    for(int i = 0; i < size; i++)
        classList[i] = cls[i];
}

string Student::getName() const{
    return name;
}

string* Student::getclassList() const{
    return classList;
}

int Student::getnumClasses() const{
    return numClasses;
}

Student Student::operator=(const Student& obj){
    setName(obj.getName());
    numClasses = obj.numClasses;
    classList = new string[numClasses];

    for(int i = 0; i < numClasses; i++)
        classList[i] = obj.classList[i]; 

    return *this;
}

void Student::user_input(){
    cout << " Enter Name : ";
    cin >> name;
    
    cout << " Enter Number of Classes : ";
    cin >> numClasses;

    classList = new string[numClasses];

    for(int i = 0; i < numClasses; i++){
        cout << "Enter name of the " << i+1 << " course : ";
        cin >> classList[i]; 
    }
    
}

void Student::listclasses(){
    for(int i = 0; i < numClasses; i++)
        cout << "Class " << i+1 << " : " << classList[i];
}

void Student::reset(){
    numClasses = 0;
    delete classList;
}

int main(){

    Student test1;

    Student test2;

    cout << "Default consturctor : Name : " << test1.getName() << " , number of classes : " 
    << test1.getnumClasses() << endl;

    cout << "user input on test2 : " << endl;
    test2.user_input();

    cout << " get class list : " << test2.getclassList() << endl;

    Student test3;

    test3 = test2;

    cout << "= operator test : " << endl 
    << " Test2 : " << endl
    << "Name : "<< test2.getName() << endl
    << "Number of Classes : " << test2.getnumClasses() << endl
    << "Class list : " << *test2.getclassList() << endl   
    << " Test3 : " << endl
    << "Name : "<< test3.getName() << endl
    << "Number of Classes : " << test3.getnumClasses() << endl
    << "Class list : " << *test3.getclassList() << endl;

    return 0;
}