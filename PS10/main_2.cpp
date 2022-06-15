#include <iostream>

using namespace std;

class Payment{
    public:
        Payment();
        void setPayment(float input) { payment = input; }
        float getPayment() const { return payment; }

        void paymentDetail();
    private:
        float payment;
};

class CashPayment : public Payment{
    public:
        CashPayment();
        void paymentDetail();
};

class CreditCardPayment : public Payment{
    public:
        CreditCardPayment();
        void paymentDetail();
};

void Payment::paymentDetail(){
    cout << "Amount of payment : " << payment << endl;
}

Payment::Payment() : payment(0) {
    //empty
}

CashPayment::CashPayment(){
    //empty
}

void CashPayment::paymentDetail(){
    cout << "Payment is in cash and amount is " << getPayment() << endl;
}

CreditCardPayment::CreditCardPayment(){
    //empty
}

void CreditCardPayment::paymentDetail(){
    cout << "Payment is in credit card payment format and amount is " << getPayment() << endl;
}

int main(){

    CashPayment test;

    cout << "Cash Payment test : " << endl;

    test.paymentDetail();
    
    cout << endl;

    test.setPayment(456.87);
    
    test.paymentDetail();
    
    cout << endl;

    CreditCardPayment test1;

    cout << "Credit Card Payment test : " << endl;

    test1.paymentDetail();

    cout << endl;

    test1.setPayment(5138.53);

    test1.paymentDetail();

    cout << endl;

    Payment test2;

    cout << "Payment test : " << endl;

    test2.paymentDetail();

    cout << endl;

    test2.setPayment(546.47);

    test2.paymentDetail();

    cout << endl;

    return 0;
}