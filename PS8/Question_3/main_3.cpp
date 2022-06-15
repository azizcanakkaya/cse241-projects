#include "f.h"
#include "g.h"
//including classes that we build
int main(){
    //calling function f of f.h library from namespace A
    A::f();
    //calling function g of g.h library from namespace A
    A::g();

    return 0;
}