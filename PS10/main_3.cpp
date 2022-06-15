#include <iostream>
#include <string>

using namespace std;


class Document{
    public:
        Document();
        inline string getText() const { return text; }
        inline void setText(string input ) { text = input; }
        Document operator=(const Document& obj);

    private:
        string text;
};

class Email : public Document{
    public:
        Email();

        inline void setSender(string input) { sender = input; }
        inline void setRecipient(string input) { recipient = input; }
        inline void setTitle(string input) { title = input; }

        inline string getSender() const { return sender; }
        inline string getRecipient() const { return recipient; }
        inline string getTitle() const { return title; }

        Email operator=(const Email& obj );

    private:
        string sender, recipient, title;
};

class File : public Document{
    public:
        File();

        inline void setPathname(string input) { pathname = input; }

        inline string getPathname() const { return pathname; }

        File operator=(const File& obj);
    private:
        string pathname;
};


Document::Document() : text("----"){
    //empty
}

Document Document::operator=(const Document& obj){
    this->text = obj.text;

    return *this;
}

Email::Email() : sender("-"), recipient("-"), title("-"){
    //empty
}

Email Email::operator=(const Email& obj){
    this->sender = obj.sender;
    this->recipient = obj.recipient;
    this->title = obj.title;

    this->setText(obj.getText());

    return *this;
}

File::File() : pathname("/") {
    //empty
}

File File::operator=(const File& obj ){
    this->pathname = obj.pathname;

    this->setText(obj.getText());

    return *this;
}
 
int main(){

    Document test;

    Document test2;

    test2.setText("This is a document");

    cout << endl << "Equality test with test and test 2  : " << test.getText() << endl;
    
    test = test2;

    cout << test.getText() << endl << endl;

    Email test1;

    Email test3;

    test1.setText("This is an email");

    cout << test1.getText() << endl;

    cout << endl << "Equality test with test 3 and test 1  : " << test3.getText() << endl;

    test3 = test1;

    cout << test3.getText() << endl << endl;

    test1.setSender("Aziz Can");
    test1.setRecipient("Gökhan Kaya");
    test1.setTitle("Assignment");

    cout << "Email test : " << endl << "Sender : " << test1.getSender() << endl
    << "Recipent : " << test1.getRecipient() << endl
    << "Title : " << test1.getTitle() << endl
    << "Text : " << test1.getText() << endl << endl; 

    File f;

    f.setText("This is a File");
    f.setPathname("C:/Desktop");

    cout << "File test : " << endl
    << "Path : " << f.getPathname() << endl
    << "Text : " << f.getText() << endl;

    return 0;
}