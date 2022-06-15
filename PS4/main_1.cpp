#include <iostream>
#include <vector>
#include <string>


using namespace std;

/////////////////////////////////////////////////////////////////
//Class Grade
/////////////////////////////////////////////////////////////////
class Grade{
    public:
        //constructors
        Grade();                                            //default constructor 
        Grade(int quiz1, int quiz2, int mid, int fin);      //constructor with parameters
        
        //setters
        void set_quiz1(const int qz1);                      //setter for quiz 1 
        void set_quiz2(const int qz2);                      //setter for quiz 2
        void set_midterm(const int mid);                    //setter for midterm
        void set_final(const int fin);                      //setter for finak

        //getters
        int get_quiz1() const { return quiz_1; }            //getter for quiz 1    
        int get_quiz2() const { return quiz_2; }            //getter for quiz 2
        int get_midterm() const { return midterm; }         //getter for midterm    
        int get_final() const { return final; }             //getter for final
        float get_overall() const { return overall; }       //getter for overall score
        char get_grade() const { return grade; }            //getter for Character Grade

        //functiıns
        void out();                         //display function
        void calculate_overall();           //overall point calculation function
        void grade_calc();                  //grade calculation function

    private:
        //parameters
        int quiz_1, quiz_2;
        int midterm;
        int final;
        float overall;
        char grade;
};

/////////////////////////////////////////////////////////////////
//Struct Student
/////////////////////////////////////////////////////////////////
struct Student{
    //vector of grade class
    vector<Grade> student;

    //functions
    void out(int index);                        //displaying student performance
    void resize(int size);                      //sizer for student vector
    void set(int index,const Grade& obj);       //setting data in a designated index
    char operator[](int index) const;           //operator overloaded for getter
    void input(const Grade& in);                //push_back input

}student;

////////////////////////////////////////////////////////
//Class Functions
////////////////////////////////////////////////////////

Grade::Grade() : quiz_1(0), quiz_2(0), midterm(0), final(0){
    //calculating other datas
    calculate_overall();
    grade_calc();
}

Grade::Grade(int quiz1, int quiz2, int mid, int fin) : quiz_1(quiz1), quiz_2(quiz2), midterm(mid), final(fin){
    //setting other data
    calculate_overall();
    grade_calc();
}

void Grade::calculate_overall(){
    //calculating score with their effects to the overall score
    overall = final*0.5 + midterm*0.25 + (quiz_1 + quiz_2)*1.25;
}

void Grade::set_final(const int fin){
    //checking final score and setting
    if( fin >= 0 && fin <= 100 )
         final = fin;
    else
        final = 0;
}

void Grade::set_midterm(const int mid){
    //checking midterm and setting
    if( mid >= 0 && mid <= 100 )
         midterm = mid;
    else
        midterm = 0;
}

void Grade::set_quiz1(const int qz1){
    //checking quiz 1 and setting
    if( qz1 >= 0 && qz1 <= 10 )
         quiz_1 = qz1;
    else
        quiz_1 = 0;
}

void Grade::set_quiz2(const int qz2){
    //checking quiz 2 and setting
    if( qz2 >= 0 && qz2 <= 10 )
         quiz_2 = qz2;
    else
        quiz_2 = 0;
}

void Grade::grade_calc(){
    //check for characterized grade score
    if( overall >= 90 )
        grade = 'A';
    else if( overall < 90 && overall >= 80)  
        grade = 'B';
    else if( overall < 80 && overall >= 70 )
        grade = 'C';
    else if( overall < 70 && overall >= 60 )
        grade = 'D';
    else
        grade = 'F';
}

void Grade::out(){
    //output display of the students performance
    cout << "Grade : " << get_grade() << "  Overall : " << get_overall() << endl;
}

//////////////////////////////////////////////////////////////////////////
//Struct Functions
//////////////////////////////////////////////////////////////////////////

void Student::input(const Grade& in){
    //input pushback to the vector
    student.push_back(in);
}

char Student::operator[](int index) const{
    //checking if the index is lesser than size of the vector or not and then sending out the input according to it
    if( student.size() > index || index >= 0 )
        return student[index].get_grade();
    else
        exit(1);
}

void Student::set(int index,const Grade& obj){
    //setting a class data in a designated index
     if( index <= student.size() && index >= 0 )
        student[index] = obj;
    else
        exit(0);
    

}

void Student::resize(int size){
    Grade temp;
    //resizing vector and sending default constructor to every element
    student.resize(size,temp);
}

void Student::out(int index){
    //output display in the designated index
    student[index].out();
}

//////////////////////////////////////////////////////////////////////////
//Main Function
//////////////////////////////////////////////////////////////////////////

int main(){

    //test of the constructor with parameter
    Grade test(7,10,90,95);
    test.out();

    int counter = 0;
    int index,qz1,qz2,mid,fin;

    //getting input of the 5 student
    for(int i = 0; i < 5; i++){
        cin >> index >> qz1 >> qz2 >> mid >> fin;
        Grade temp(qz1,qz2,mid,fin);
        student.input(temp);
    }

    //displaying student that entered by the user
    for(int i = 0; i < 5; i++){
        cout << "Student " << i+1 << " : ";
        student.out(i);
    }

    return 0;
}