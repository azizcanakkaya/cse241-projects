#include <iostream>

using namespace std;

class IntList{
    public:
        IntList();
        IntList(int input);

        void display();
        void rearrange();
        void nextData(int data); 

        IntList* getLink() const { return link; }
        int getData() const { return data; }

        void setData(int input) { data = input; }
        void setLink(IntList *next) { link = next; }

    protected:
        int data;
        IntList *link;
};

IntList::IntList(int input) : data(input), link(NULL){
    //empty
}

IntList::IntList() : data(0), link(NULL){
    //empty
}

void IntList::nextData(int data){ 
    IntList* temp = new IntList(data); 
    temp->link = link; 
    link = temp; 
}

void IntList::display(){ 
    IntList* temp = link; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->link; 
    } 
}

void IntList::rearrange() {
        IntList *current = link; 
        IntList *prev = NULL;
        IntList *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->link; 
  
            // Reverse current node's pointer 
            current->link = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        link = prev; 
    } 

int main(){

    IntList test;

    for(int i = 0; i < 10; i++ )
        test.nextData(i*3);

    cout << "Original form of the linked list : " << endl;

    test.display();

    cout << endl << endl << "Reversed form of the linked list : " << endl;

    test.rearrange();

    test.display();

    cout << endl;

    return 0;
}