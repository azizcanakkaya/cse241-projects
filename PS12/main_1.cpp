#include <iostream>

using namespace std;

template <typename T1, typename T2>
void absolute(T1 input1, T2 input2){
    cout << "T1 : " << abs(input1) << ", T2 : " << abs(input2) << endl;
}

int main(){

    cout << "Double, Double : " << endl;
    absolute(213,234.532);

    cout << endl << "Char, Double : " << endl;
    absolute('T',234.532);

    cout << endl << "Float, Int : " << endl;
    absolute(-24.2,478);

    return 0;
}