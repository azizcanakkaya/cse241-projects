#include <iostream>

using namespace std;

class CharPair{
    public:
        CharPair();
        CharPair(int in_size);
        CharPair(int in_size, char input[]);
        int getSize() const { return size; }

        char& operator[](int index);
        char operator[](int index) const;

    private:
        char first[100];
        char second[100];
        int size;
};

CharPair::CharPair() : size(10) {
    for(int i = 0; i < size; i++ ){
        first[i] = '#';
        second[i] = '#';
    }
}

char& CharPair::operator[](int index){
    if( index <= size && index >= 0)
        return first[index];
    else{
        cout << "Invalid index!" << endl;
        exit(1);
    }
}

char CharPair::operator[](int index) const{
    if( index <= size && index >= 0)
        return first[index];
    else{
        cout << "Invalid index!" << endl;
        exit(1);
    }
}

CharPair::CharPair(int in_size) : size(in_size) {
    for(int i = 0; i < size; i++){
        first[i] = '#';
        second[i] = '#';
    }
}

CharPair::CharPair(int in_size, char input[]) : size(in_size/2){
    for(int i = 0; i < in_size; i++){
        for(int j = 0; j < size; j++){
            first[j] = input[i];
            second[j] = input[i+1];
            i++;
        }
    }
}

int main(){

    char arr[6] = {'a','b','c','d','e','f'};

    CharPair test1;
    CharPair test2(6,arr);
    CharPair test3(4);

    cout << "Output of deafult constructor : " << endl;

    for(int i = 0; i < 3; i++){
        cout << test2[i] << " ";
    }

    return 0;   
}