#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string input;
    char *head, *tail;
    int tail_tracker;

    cout << "Enter the string : ";
    cin >> input;
    cout << endl;

    head = (char*) malloc ((input.length())*sizeof(char));
    tail = (char*) malloc (input.length()*sizeof(char));

    tail_tracker = input.length();

    for( int i = 0; i < input.length(); i++ ){
        head[i] = input[i];
        tail[tail_tracker] = input[tail_tracker-1];
        cout << " Head : " << head[i] << " , Tail : " << tail[tail_tracker] << " , Iteration : " << i << endl;
        tail_tracker--;
    }
    cout << endl;

    return 0;
}