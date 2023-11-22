#include <iostream>
#ifndef GAMEOBJ_H
#define GAMEOBJ_H

using namespace std;

int convertMove(int row, int col, int size);

namespace GameObj{
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
        //ConvertMove to be implemented by Hannah
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
        this->winner = -1;
        for(int i = 0; i < size*size; i++){
            (*subgamesPtr)[i].init(size);
        }
    }

    void playsMove(int row, int col, int player, int board){
        subGame** subgamesptr = this->subgamesPtr;
        (*subgamesptr)[board].playsMove(row, col, player);
    }
    
    void setOverallWinner(){
        subGame** subgamesPtr = this->subgamesPtr;
        size_t size = this->size;
        int* subWinners = this->subWinners;
        int winner = this->winner;
        /*
        Win conditions:
        - Someone wins an entire row (subgames[const][var] is all equal for some const and all var < size)
        - Someone wins entire column
        - Someone wins diagonal
        */


    }

    subGame** getSubgamesPtr(){
        return this->subgamesPtr;
    }

    int getSize(){
        return this->size;
    }

    void rawDump(){
        cout << "You are using a debug feature... Just so you know" << endl;
        subGame** subgamesptr = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size; board++){
            for(int elem = 0; elem < size; elem++){
                cout << (*subgamesptr)[board].getBoard()[elem];
            }
            cout << endl;
        }
        cout << endl;
    }

    void formattedOutput(){
        subGame** subgamesptr = this->subgamesPtr;
        size_t size = this->size;
    }

    void destruct(){
        subGame** subgamesptr = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size; board++){
            (*subgamesptr)[board].destruct();
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

    bool* getPlayable(){
        return this->playable;
    }

    void update(){
        subGame** subgamesptr = this->subgamesPtr;
        size_t size = this->size;
        for(int board = 0; board < size*size; board++){
            this->playable[board] = (*subgamesptr)[board].getPlayable();
            this->subWinners[board] = (*subgamesptr)[board].getWinner();
        }
        this->setOverallWinner(); 
    }
    //Hannah's work
};
}

#endif