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
        this->size = size;
        this->board = new int[size * size];
    }

    void setWinner(int* board){
        //sets the winner
    }

    void playsMove(int row, int col, int player){
        int move = convertMove(row, col, this->size);
        //Plays the row, col.
        //Needs conversion of {int row, int col} into int.
    }

    int getWinner(){
        return this->winner;
    }

    int getSize(){
        return this->size;
    }

    int convertMove(int row, int col, int size){
        int convertedMove;
        //Some logic here...
        return convertedMove;
     }
};

class Game: public subGame{
//Represents the whole game of games.
//Since Game inherits subGame, it should have access to its methods. Like:
//Game.setWinner() should set the winner of the whole game.
private: 
    int size;
    subGame* subgames;
    int winner;

public: 
    void init(int size){
        this->size = size;
        this->subgames = new subGame[size * size];
        for(int i = 0; i < size*size; i++){
            subgames[i].init(size);
        }
    }

    void playsMove(int row, int col, int player, int* lastPlay){
        int board = convertMove(lastPlay[0], lastPlay[1], this->size);
        subgames[board].playsMove(row, col, player); 
    }
};

void format(Game game){
    //Formats the thing, somehow.
}

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}

void init(){
    cout << "Please enter the names of each player..." << endl;
    string player1, player2;
    string players[] = {player1, player2};
    int size;
    cin >> player1 >> player2;
    cout << "Please enter the size of the game and the subgame. Note that the game and subgame must be of the same size." << endl;
    cin >> size;
    Game game;
    game.init(size);
}

int main(){
    init();

    return 0;
}