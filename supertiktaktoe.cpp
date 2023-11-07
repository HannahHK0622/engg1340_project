#include <iostream>
#include <string>

using namespace std;

class subGame{
private:
    size_t size;
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
};

class Game{

private: 
    size_t size;
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

    subGame* getSubgames(){
        return this->subgames;
    }

    int getSize(){
        return this->size;
    }
};


int convertMove(int row, int col, int size){
    int convertedMove;
    //Some logic here...
    return convertedMove;
    }

void printFormat(Game game){
    subGame* subgames = game.getSubgames();
}

void printRaw(Game game){
    subGame* subgames = game.getSubgames();
    size_t size = game.getSize();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << subgames[i][j];
        }
        cout << endl;
    }

}

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}

int main(){
    string player1, player2;
    string players[] = {player1, player2};
    char playerToken[] = {'X', 'O'};
    bool player = 0;
    size_t size;
    cin >> player1 >> player2;
    cout << "Please enter the size of the game and the subgame. Note that the game and subgame must be of the same size." << endl;
    cin >> size;
    Game game;
    game.init(size);


    return 0;
}



