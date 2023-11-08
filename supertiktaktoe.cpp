#include <iostream>
#include <string>

using namespace std;

class subGame{
private:
    size_t size;
    int* board; 
    int winner;
    bool playable;

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

    bool getPlayable(){
        return this->playable;
    }

    int* getBoard(){
        return this->board;
    }


    void destruct(){
        delete[] board;
    }
    //Jintao's work
};

class Game{

private: 
    size_t size;
    subGame** subgamesPtr;
    bool* playable;
    int* subWinners;
    bool gameOver;
    int winner;

public: 
    void init(int size){
        this->size = size;
        subGame* newSubgames = new subGame[size * size];
        this->playable = new bool[size*size];
        this->subgamesPtr = &newSubgames;
        for(int i = 0; i < size*size; i++){
            (*subgamesPtr)[i].init(size);
        }
    }

    void playsMove(int row, int col, int player, int board){
        
    }
    
    void setOverallWinner(subGame** subgamePtr){


    }

    subGame** getSubgamesPtr(){
        return this->subgamesPtr;
    }

    int getSize(){
        return this->size;
    }

    void rawDump(){
        cout << "You are using a debug feature... Just so you know" << endl;
        subGame** subgames = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size; board++){
            for(int elem = 0; elem < size; elem++){
                cout << (*subgames)[board].getBoard()[elem];
            }
            cout << endl;
        }
        cout << endl;
    }

    void formattedOutput(){
        subGame** subgames = this->subgamesPtr;
        size_t size = this->size;
    }

    void destruct(){
        subGame** subgames = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size; board++){
            (*subgames)[board].destruct();
        }
        delete[] subgamesPtr;
        delete[] playable;
        delete[] subWinners;
    }

    bool getGameOver(){
        return this->gameOver;
    }

    bool getWinner(){
        return this->winner;
    }

    void update(){
        subGame** subgames = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size*size; board++){
            this->playable[board] = (*subgames)[board].getPlayable();
            this->subWinners[board]=(*subgames)[board].getWinner();
        }
        this->setOverallWinner(subgames); 
    }
    //Hannah's work
};


int convertMove(int row, int col, int size){
    int convertedMove;
    //Some logic here...
    return convertedMove;

    //Jintao's work
    }

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}

void debug(Game game){
    cout << "debug active" << endl;
    //Debug stuff goes here and please PLEASE delete before deadline
    game.rawDump();
}

int chooseBoard(int* lastPlay, size_t size){
    int board;
    return board;
}

int* getDefaultLastPlay(){
    //Gets the default value
    int row=-1, col=-1; //{-1, -1} should be impossible, but it still fits int* so I guess?
    int default[] = {row, col};
    return default;
}

int main(){
    const bool debugging = true;

    int* lastPlay = getDefaultLastPlay();
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

    if(debugging){
        debug(game);
    }
    

    //Game logic begins here
    while(true){
        int board = chooseBoard(lastPlay, game.getSize());


        if(game.getGameOver()){
            break;
        }
    }
    declareWinner(players[game.getWinner()]);
    game.destruct();
    return 0;
}



