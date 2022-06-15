////////////////////////////////////////////////////////////////
// Name : Aziz Can                                            //
// Surname : Akkaya                                           //
// Number : 1801042250                                        //
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//Image Class(Editor)
/////////////////////////////////////////////////////////////////////////////

class Image{
    public:
        //default constructor
        Image();                    //Default Constructor
        ~Image();                   //Destructor
        Image(const Image& obj);    //Copy Constructor
        //Menu Functions
        void menu();
        void open_image_menu();
        void save_menu();
        void scripts_menu();
        void gray_scale_menu();
        //Functions
        void gray_scale();
        void read_file();
        void wrtite_file();
        void printStatus();
        void resize(int x,int y);
        //Getters
        string getStatus() const;
        string getFileName() const;
        int getWidth() const;
        int getHeight() const;
        int getMax() const;
        string getImageFormat() const;
        int getBlue(int x,int y) const;
        int getGreen(int x,int y) const;
        int getRed(int x,int y) const;
        //Setters
        void setStatus(string in);
        void setFileName(string in);
        void setWidth(int wd);
        void setHeight(int hd);
        void setMax(int mx);
        void setImageFormat(string ff);
        void setB_cell(int x, int y, int value);
        void setG_cell(int x, int y, int value);
        void setR_cell(int x, int y, int value);
        //Operator Overload
        void operator=(const Image& obj);
        Image operator+(const Image& obj);
    private:
        //RGB Data kept in 2D array
        int **red;
        int **blue;
        int **green;
        int width, height, max;                     //number of pixels for width and height and maximum pixel value
        string image_format, status, file_name;     //image format data and general datas for handling them         
} image[2]; //0 is for merging, 1 and 2 is for to image processing

/////////////////////////////////////////////////////////////////////////////
//Class Functions
/////////////////////////////////////////////////////////////////////////////

//Default Constructor
Image::Image() : width(0), height(0), image_format("P3"), status("closed"), max(255){
    //empty
    image[0].setStatus("Not Merged"); //setting the status of the merging file
}
//Destructor
Image::~Image(){
    //checking if the width and height are not zero
    if( width != 0 && height != 0 ){
        for(int i = 0; i < width; ++i) {
            //deleting rows
            delete[] red[i];
            delete[] green[i];
            delete[] blue[i];   
        }
        //deleting columns
        delete []red;
        delete []blue;
        delete []green;
    }
}
//Copy Constructor
Image::Image(const Image& obj){
    *this = obj;
}

/////////////////////////////////////////////////////////////////////////////
//GETTERS
/////////////////////////////////////////////////////////////////////////////

string Image::getFileName() const{
    return file_name;
}

string Image::getStatus() const{
    return status;
}

int Image::getWidth() const{
    return width;
}

int Image::getHeight() const{
    return height;
}

int Image::getMax() const{
    return max;
}

string Image::getImageFormat() const{
    return image_format;
}

int Image::getBlue(int x, int y) const{
    return blue[x][y];
}

int Image::getGreen(int x, int y) const{
    return green[x][y];
}

int Image::getRed(int x, int y) const{
    return red[x][y];
}

/////////////////////////////////////////////////////////////////////////////
//SETTERS
/////////////////////////////////////////////////////////////////////////////

void Image::setStatus(string in){
    status = in;
}

void Image::setFileName(string in){
    file_name = in;
}

void Image::setWidth(int wd){
    width = wd;
}

void Image::setHeight(int hd){
    height = hd;
}

void Image::setMax(int mx){
    max = mx;
}

void Image::setImageFormat(string ff){
    image_format = ff;
}

void Image::setB_cell(int x, int y, int value){
    if( x < height && y < width && value < max+1)
        blue[x][y] = value;
    else if( value > max && x < height && y < width)
        blue[x][y] = max;
    else
        blue[x][y] = 0;
}

void Image::setG_cell(int x, int y, int value){
    if( x < height && y < width && value < max+1)
        green[x][y] = value;
    else if( value > max && x < height && y < width)
        green[x][y] = max;
    else
        green[x][y] = 0;
}

void Image::setR_cell(int x, int y, int value){
    if( x < height && y < width && value < max+1)
        red[x][y] = value;
    else if( value > max && x < height && y < width)
        red[x][y] = max;
    else
        red[x][y] = 0;
}

/////////////////////////////////////////////////////////////////////////////
//Operator Overloading
/////////////////////////////////////////////////////////////////////////////

void Image::operator=(const Image& obj){

    this->resize(obj.getHeight(), obj.getWidth());
    
    this->setMax(obj.getMax());
    this->setImageFormat(obj.getImageFormat());

    for(int i = 0; i < this->getHeight(); i++){
        for(int j = 0; j < this->getWidth(); j++){
            this->setR_cell(i, j, obj.getRed(i,j));
            this->setB_cell(i, j, obj.getBlue(i,j));
            this->setG_cell(i, j, obj.getGreen(i,j));   
                
        }
    }

}

Image Image::operator+(const Image& obj){
    Image temp;
    if( width == obj.getWidth() && height == obj.getHeight() ){
        temp = obj;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                temp.setR_cell(i, j, obj.getRed(i,j) + this->getRed(i,j) );
                temp.setB_cell(i, j, obj.getBlue(i,j) + this->getBlue(i,j) );
                temp.setG_cell(i, j, obj.getGreen(i,j) + this->getGreen(i,j) );   
            }
        }
    }
    return temp;
}

/////////////////////////////////////////////////////////////////////////////
//Class Functions
/////////////////////////////////////////////////////////////////////////////

void Image::resize(int x, int y){
    //checking for row and column values for to delete
    if( height != 0 && width != 0){
        //setting height and width
        setHeight(x);
        setWidth(y);
        //deleting rows
        for(int i = 0; i < width; ++i) {
            delete[] red[i];
            delete[] green[i];
            delete[] blue[i];   
        }
        //deleting columns
        delete []red;
        delete []blue;
        delete []green;
        //set up of width
        red = new int *[x];
        green = new int *[x];
        blue = new int *[x];
        //set up of height
        for(int i = 0; i < x; i++){
            red[i] = new int [y];
            green[i] = new int[y];
            blue[i] = new int[y];
        }
    }
    else{  
        //setting height and width      
        setHeight(x);
        setWidth(y);
        //set up of width
        red = new int *[x];
        green = new int *[x];
        blue = new int *[x];
        //set up of height
        for(int i = 0; i < x; i++){
            red[i] = new int[y];
            green[i] = new int[y];
            blue[i] = new int[y];
        }
    }

}

void Image::printStatus(){
    //status display of images
    cout << endl << "File Status : " << endl
    << "File 0 : " << image[0].getStatus() << endl;

    if( image[1].getStatus() == "open")
        cout << "File 1 : open, name :  " << image[1].getFileName() << endl;
    else
        cout << "File 1 : closed" << endl;

    if( image[2].getStatus() == "open" )
        cout << "File 2 : open, name :  " << image[2].getFileName() << endl;
    else
        cout << "File 2 : closed" << endl;
}

/////////////////////////////////////////////////////////////////////////////
//Menu Functions
/////////////////////////////////////////////////////////////////////////////

void Image::menu(){
    //Integer for to get from user
    int input;
    //Displaying Status
    printStatus();
    //main menu display
    cout << "MAIN MENU" << endl 
    << "0 - Exit" << endl
    << "1 - Open An Image(D)" << endl
    << "2 - Save Image Data(D)" << endl
    << "3 - Scripts(D)" << endl
    << "4 - Merge Image Files" <<endl;
    //getting input from the user
    cin >> input;
    //checking the input and sending them to subfunctions accordingly
    if( input == 0 )
         exit(0);
    else if( input == 1 )
        open_image_menu();
    else if( input == 2 )
        save_menu();
    else if( input == 3 )
        scripts_menu();
    else if( input == 4 ){
        image[0] = image[2] + image[1];
        image[0].setStatus("Merged");
    }        
    else    
        exit(0);        //executing if there is an invalid input
}

void Image::open_image_menu(){
    //input from user
    int input,image_number;
    //open image menu display
    printStatus();
    cout << "OPEN AN IMAGE MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter The Name Of The Image File" << endl;
    cin >> input;           //getting input
    //checking input and recınfiguration
    if( input == 0 )
        menu();                     
    else if( input == 1 ){
        cout << "Enter the Number of File (1 or 2) : ";
        cin >> image_number;
        image[image_number].read_file();
    }        
    else
        exit(0);             //in case for invalid input execution      
}

void Image::read_file(){
    //datas
    string input,iff;          //input for file name
    ifstream img;        //input file
    int r,b,g,w,h,m;
    //getting file name
    cin >> input;
    //openining file
    img.open(input);
    //checking if the is open
    if( img.is_open() ){
        //setting header data of the ppm file
        img >> iff >> w >> h >> m;
        //setting file data
        resize(h, w);
        setImageFormat(iff);
        setMax(m);
        setStatus("open");
        setFileName(input);
        //writing values for ppm file
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++ ){
             img >> r >> g >> b;
             setR_cell(i,j,r);
             setG_cell(i,j,g);
             setB_cell(i,j,b);
            }
        }
    }
    else
        exit(0);        //Execution for invalid input

    img.close();      //closing file
    open_image_menu();  //redirecting menu
}

void Image::save_menu(){
    //input from user
    int input,file_number;
    //save image menu display
    printStatus();
    cout << "SAVE IMAGE DATA MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter A File Name" << endl;
    cin >> input;            //Getting input
    //reconfiguration according to input
    if( input == 0 )
        menu();
    else if( input == 1 ){
        cout << "Enter Number of the File (0, 1 or 2) : ";
        cin >> file_number;
        image[file_number].wrtite_file();
    }
    else    
        exit(0);            //execution in case of invalid input
}

void Image::wrtite_file(){
    //data
    string input;           //input for file name
    ofstream new_file;      //output file 
    cin >> input;
    //opening file
    new_file.open(input);
    //checking if the file is open or not
    if( new_file.is_open() ){
        //writing the header
        new_file << getImageFormat() << endl
        << getWidth() << " " << getHeight() << endl
        << getMax() << endl;
        //writing the pixels
        for(int i = 0; i < getHeight(); i++ ){
            for(int j = 0; j < getWidth(); j++){
                new_file << getRed(i,j) << " " << getGreen(i,j) << " " << getBlue(i,j) << " ";
            }
            new_file << endl;
        }
    }
    else
        exit(0);            //execution for invalid input

    new_file.close();       //closing file
    save_menu();            //redirecting menu
}

void Image::scripts_menu(){
    //input data from user
    int input;
    //scripts menu display
    cout << "SCRIPTS MENU" << endl
    << "0 - UP" << endl
    << "1 - Convert To GrayScale(D)" << endl;
    cin >> input;           //getting user input
    //checking and rediretion according to input
    if( input == 0)
        menu();
    else if( input == 1 )
        gray_scale_menu();
    else
        exit(0);            //execution for invalid input
}

void Image::gray_scale_menu(){
    //user input
    int input,file_number;
    //grayscale data menu display
    cout << "CONVERT TO GRAYSCALE MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter Coefficients for RED GREEN And BLUE Channels." << endl;
    cin >> input;           //getting the input
    //redirection according to input
    if( input == 0 )
        scripts_menu();
    else if( input == 1 ){
        cout << " Enter the Number of the File (0, 1 or 2) : ";
        cin >> file_number;
        image[file_number].gray_scale();
    }
        
    else
        exit(0);        //execution for invalid input
}

void Image::gray_scale(){
    //data
    double c_r, c_g, c_b;
    int RED, BLUE, GREEN;
    //gettin grayscale coeffients
    cin >> c_r >> c_g >> c_b;
    //checking them( they have to be between 0 and 1)
    if( c_r <= 1 && c_r >= 0 && c_g <= 1 && c_g >= 0 && c_b <= 1 && c_b >= 0 ){
        //setting every pixels one by one
        for( int i = 0; i < height; i++ ){
            for( int j = 0; j < width; j++){
                //calculation of parameters
                RED = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
                GREEN = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
                BLUE = (int)(c_r*red[i][j] + c_g*green[i][j] + c_b*blue[i][j]);
                
                //checking the parameters for rgb range and setting them accordingly
                setR_cell(i,j,RED);
                setB_cell(i,j,BLUE);
                setG_cell(i,j,GREEN);
            }
        }
    }
    else
        exit(0);          //execution for invalid input

    gray_scale_menu();    //redirection to gray scale menu
}

int main(){
    //test object
    Image test;
    //starting the program
    test.menu();

    return 0;
}