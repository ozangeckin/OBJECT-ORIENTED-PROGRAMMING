#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//definition Player class
class Player{
    public:
        Player();
        virtual int getGuess();
};
//default constructor Player
Player::Player(){

}
//virtual getGuess fonksiyom
int Player::getGuess(){
    return 0;
}
//definition ComputerPlayer class extends Player class
class ComputerPlayer: public Player{
    public:
        ComputerPlayer();
        virtual int getGuess();
};
//default constructor ComputerPlayer
ComputerPlayer::ComputerPlayer():Player(){

}
//initial getGuess fuction
int ComputerPlayer::getGuess(){
    int guess;
    guess=rand()%100;
    cout<<"Computer Guess : "<<guess<<endl;
    return guess;
}
//definiton HumanPlayer class extends Player class
class HumanPlayer: public Player{
    public:
        HumanPlayer();
        virtual int getGuess();
};
//default HumanPlayer constructor
HumanPlayer::HumanPlayer():Player(){
}
int HumanPlayer::getGuess(){
    int guess;
    do{
    cout<<"Enter a number guess between 0 and 99 : "<<endl;
    cin>>guess;
    }while((guess<0)||(guess>99));

    return guess;
}
//global function
bool checkForWin(int guess, int answer);
void play(Player &player1,Player &player2);
//main function
int main(){
    HumanPlayer  Player1;
    ComputerPlayer Player2;
    //game
    play(Player1,Player2);

    return 0;
}

bool checkForWin(int guess, int answer)
{
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}

void play(Player &player1,Player &player2)
{
    int answer = 0, guess = 0;
    answer = rand( ) % 100;
    bool win = false;
    while (!win)
    {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess( );
        win = checkForWin(guess, answer);
        if (win) return;
        
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess( );
        win = checkForWin(guess, answer);
    }
}
