#include <iostream>
#include <cstring>

using namespace std;

void reverser(char arr[], int bound1, int bound2) {
    char temp;

	if (bound1 > bound2)
	    return;			   
	else{
		temp = arr[bound2];
		arr[bound2] = arr[bound1];
		arr[bound1] = temp;
		  
        bound1++;
        bound2--;

		reverser(arr, bound1, bound2);  
	}
}

string reverseString(string input){
    char temp_array[ input.length()+1];
    
    strcpy(temp_array,input.c_str() );

    reverser(temp_array, 0, input.length()-1);
    
    return temp_array;  
}

int main() {

    
    string test = "ABCDE";
    cout << "Complete reverser test with string : " << endl << test << endl;
    test = reverseString(test);
    cout << test <<endl;

    char test1[] = "ABCDE";
    cout << "reverser test : " << endl << test1 << endl;
    reverser(test1,1,4);
    cout << test1 << endl;

    return 0;
}