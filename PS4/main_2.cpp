#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////
//Main Function
/////////////////////////////////////////////////////
int main(){

    //parameters needed
    vector<int> suitors;
    int size,eliminated,counting;
    int iter = 0;

    //input of suitors
    cout << "Enter the number of suitors : ";
    cin >> size;

    //setting suitors to the vector
    for(int i = 1; i < size+1; i++){
        suitors.push_back(i);
    }

    //iteration loop
    while( size != 1 ){

        //iterator increase
        iter += 2;
        
        //iterator position set
        if( iter > size )
            iter = iter - (size);
        else if( iter == size )
            iter = 0;
        
        //temporary parameter for the eliminated input to use it for displaying
        eliminated = suitors[ iter ];

        //eliminatin suitor and decreasing size
        suitors.erase( suitors.begin() + iter );
        size--;
        
        //setting position of the element which will be started on the next iteration
        if( iter == size )
            counting = 0;
        else
            counting = iter;

        //displayin remaining suitors
        for( int i = 0; i < size; i++ ){
            cout << suitors[i];
        }
        
        //checking if there is a winner and with it displaying the output according to it
        if( size != 1 )
            cout << " suitor " << eliminated << " eliminated, continue counting from " << suitors[counting] << endl;
        else
            cout << " suitor " << eliminated << " eliminated, " << suitors[counting] << " is the lucky winner" << endl;
            
    }

    return 0;
}