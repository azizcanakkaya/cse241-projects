////////////////////////////////////////////////////////////////
// Name : Aziz Can                                            //
// Surname : Akkaya                                           //
// Number : 1801042250                                        //
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//Image Class(Editor)
////////////////////////////////////////////////////////////////////////////

class Image{
    public:
        //default constructor
        Image();                    //We dont need any other constructor since all operations happening here
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

    private:
        //RGB Data kept in 2D array
        vector<vector <int>> red;
        vector<vector <int>> blue;
        vector<vector <int>> green;
        int width, height;              //number of pixels for width and height
        string image_format;            //image format data
};

/////////////////////////////////////////////////////////////////////////////
//Class Functions
////////////////////////////////////////////////////////////////////////////

Image::Image() : width(0), height(0), image_format("P3"){
    //empty
}

void Image::menu(){
    //Integer for to get from user
    int input;
    //main menu display
    cout << "MAIN MENU" << endl 
    << "0 - Exit" << endl
    << "1 - Open An Image(D)" << endl
    << "2 - Save Image Data(D)" << endl
    << "3 - Scripts(D)" << endl;
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
    else    
        exit(0);        //executing if there is an invalid input
}

void Image::open_image_menu(){
    //input from user
    int input;
    //open image menu display
    cout << "OPEN AN IMAGE MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter The Name Of The Image File" << endl;
    cin >> input;             //getting input
    //checking input and recınfiguration
    if( input == 0 )
        menu();                     
    else if( input == 1 )
        read_file();
    else
        exit(0);             //in case for invalid input execution      
}

void Image::save_menu(){
    //input from user
    int input;
    //save image menu display
    cout << "SAVE IMAGE DATA MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter A File Name" << endl;
    cin >> input;            //Getting input
    //reconfiguration according to input
    if( input == 0 )
        menu();
    else if( input == 1 )
        wrtite_file();
    else    
        exit(0);            //execution in case of invalid input
}

void Image::read_file(){
    //datas
    string input;          //input for file name
    ifstream image;        //input file
    //getting file name
    cin >> input;
    //openining file
    image.open(input);
    //checking if the is open
    if( image.is_open() ){
        int upper_limit;    //it will usually be 255
        //setting header data of the ppm file
        image >> image_format >> width >> height >> upper_limit;
        //setting widht of pixels
        red.resize(width);
        blue.resize(width);
        green.resize(width);
        //setting the height of every column
        for(int i = 0; i < width; i++){
            red[i].resize(height);
            blue[i].resize(height);
            green[i].resize(height);
        }
        //writing values for ppm file
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++ ){
             image >> red[j][i] >> green[j][i] >> blue[j][i];
            }
        }
        
    }
    else
        exit(0);        //Execution for invalid input

    image.close();      //closing file
    open_image_menu();  //redirecting menu
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
        new_file << image_format << endl
        << width << " " << height << endl
        << 255 << endl;
        //writing the pixels
        for(int i = 0; i < height; i++ ){
            for(int j = 0; j < width; j++){
                new_file << red[j][i] << " " << green[j][i] << " " << blue[j][i] << " ";
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

void Image::gray_scale(){
    //data
    double c_r, c_g, c_b;
    double RED, BLUE, GREEN;
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
                if( RED <= 255 )
                    red[i][j] = (int)RED;
                else
                    red[i][j] = 255;

                if( blue[i][j] <= 255 )
                    green[i][j] = (int)GREEN;
                else
                    green[i][j] = 255;
                
                if( blue[i][j] <= 255 )
                    blue[i][j] = (int)BLUE;
                else
                    blue[i][j] = 255;
            }
        }
    }
    else
        exit(0);          //execution for invalid input

    gray_scale_menu();    //redirection to gray scale menu
}

void Image::gray_scale_menu(){
    //user input
    int input;
    //grayscale data menu display
    cout << "CONVERT TO GRAYSCALE MENU" << endl
    << "0 - UP" << endl
    << "1 - Enter Coefficients for RED GREEN And BLUE Channels." << endl;
    cin >> input;           //getting the input
    //redirection according to input
    if( input == 0 )
        scripts_menu();
    else if( input == 1 )
        gray_scale();
    else
        exit(0);        //execution for invalid input
}

/////////////////////////////////////////////////////////////////////////////
//Main functions
////////////////////////////////////////////////////////////////////////////

int main(){
    //setting up editor class 
    Image editor; 
    //executing editor class from the start point of editor menu
    editor.menu();

    return 0;
}