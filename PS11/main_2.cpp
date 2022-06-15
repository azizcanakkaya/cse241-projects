#include <iostream>
#include <ctime>

using namespace std;

class Player{
    public:
        Player();
        Player(int input);

        bool checkForWin(int guess, int answer);
        void play(Player &player1, Player &player2);

        virtual int getGuess() = 0;
};

class HumanPlayer : public Player{
    public:
        HumanPlayer();
        int getGuess();
};

class ComputerPlayer : public Player{
    public:
        ComputerPlayer();
        int getGuess();
};

Player::Player(){
    //empty
}

HumanPlayer::HumanPlayer(){
    //empty
}

ComputerPlayer::ComputerPlayer(){
    //empty
}

int HumanPlayer::getGuess(){
    int temp;
    cout << "Enter your guess : ";
    cin >> temp;

    return temp;
}

int ComputerPlayer::getGuess(){
    int temp = rand() % 100;

    return temp;
}

bool Player::checkForWin(int guess, int answer){
    if (answer == guess){
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}

void Player::play(Player &player1, Player &player2){
    int answer = 0, guess = 0;
    answer = rand( ) % 100;
    bool win = false;

    while (!win){
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess( );
        win = checkForWin(guess, answer);
        
        if (win) return;
        
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess( );
        win = checkForWin(guess, answer);
        cout << endl;
        }
}

int main(){
    srand(time(NULL));

    HumanPlayer test2;
    HumanPlayer test1;

    test1.play(test2,test1);


    return 0;
}