#include <iostream>

using namespace std;

class Account{
    private:
        double balance;
    public:
        Account(){
            balance = 0;
        }

        Account( double initialDeposit){
            balance = initialDeposit;
        }

        double getBalance(){
            return balance;
        }

        // returns new balance or -1 if error
        double deposit( double amount){
            try{
                if( amount > 0 )
                    balance += amount;
                else
                    throw -1;
                
                return balance;
            }catch( int error ){
                cout << "Invalid deposit! Error : ";
                return error;
            }
        }

        // returns new balance or -1 if invalid amount
        double withdraw( double amount){
            try{
                if ((amount > balance) || (amount < 0))
                    throw -1;
                else
                    balance -= amount;
                return balance;
            }catch( int error ){
                cout << "Invalid Amount! Error : ";
                return error;
            }
        }
    };


int main(){

    Account test(1264.56);

    cout << "Balance : " << test.getBalance() << endl;
    cout << "Withdraw Attempt : " << test.withdraw(431.45) << ", New Balance : " << test.getBalance() << endl;
    
    cout << endl << "Witdraw Attempt : " << test.withdraw(100000) << endl;

    cout << endl << "Deposit Attempt : " << test.deposit(12452.123) << endl;
    cout << "Balance : "  << test.getBalance() << endl;

    cout << endl << test.deposit(-123.4321) << endl; 
    return 0;
}