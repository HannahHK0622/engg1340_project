#include <iostream>
#include <vector>
#include <string>

using namespace std;
class subGame{
private:
    int size;
    int* board;
    int winner;

public:
    void init(int size){
        this -> size = size;
        int* board = new int[size * size];
    }

    void setWinner(int* board){
        //sets the winner
    }

    void setPlay(int row, int col){
        //Plays the row, col.
        //Needs conversion of {int row, int col} into int.
    }

    int getWinner(){
        return this->winner;
    }

};
class Game: public subGame{
private: 
    int size;
    subGame* subgames;
    int winner;

public: 
    void init(int size, int subGameSize){
        this -> size = size;
        subgames = new subGame[subGameSize * subGameSize];
        for(int i = 0; i < size*size; i++){
            subgames[i].init(subGameSize);
        }
    }

    int selectBoard(int* lastPlay){
        //select board to play in
        //Depends on lastPlay which should be (int row, int col)
    }
};

void format(Game game){
    //Formats the thing, somehow.
}

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}


int main(){
    cout << "Please enter the names of each player..." << endl;
    string player1, player2;
    string players[] = {player1, player2};
    int innerSize, outerSize;
    cin >> player1 >> player2;
    cout << "Please enter the dimensions of a subgame." << endl;
    cin >> innerSize;
    cout << "Please enter the dimensions of the whole game - for example, if you want 4x4 grid of subgames, enter 4." << endl;
    cin >> outerSize;
    Game game;
    game.init(innerSize, outerSize);
    return 0;
}