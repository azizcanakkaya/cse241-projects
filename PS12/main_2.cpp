#include <iostream>
#include <string>

using namespace std;

int getProductID( int ids[], string names[],int numProducts, string target){
    try{
       for ( int i=0; i < numProducts; i++){
            if (names[i] == target)
                return ids[i];
        }
        throw -1; 
    }catch( int error ){
        cout << "Product does not exist! Error : ";
        return -1;
    }
}


int main(){
    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = {"computer","flash drive","mouse","printer","camera"};
    cout << getProductID(productIds, products, 5, "mouse") << endl;
    cout << getProductID(productIds, products, 5, "laptop")<< endl;
    cout << getProductID(productIds, products, 5, "camera")<< endl;
    
    return 0;
}