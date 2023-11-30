#include <iostream>
#include <algorithm>
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
    void init(int size) {
        this->size = size;
        this->board = new int[size * size];
        this->playable = true;
        this->winner = -1;
        std::cout << "Init subgame, size "<< size << endl;
        std::cout << "Final size: " << this->size << endl;
        std::cout << "subGame::init(int size)" << endl;
        std::cout << "address: " << this << endl;
        std::fill_n(this->board, size * size, -1);
    }

    void setWinner(int* board){
        //sets the winner
        if((board[0]==board[1]) && (board[0]==board[2])){
            if(board[0]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[3]==board[4]) && (board[3]==board[5])){
            if(board[3]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[6]==board[7]) && (board[6]==board[8])){
            if(board[6]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[0]==board[3]) && (board[0]==board[6])){
            if(board[0]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[1]==board[4]) && (board[1]==board[7])){
            if(board[1]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[2]==board[5]) && (board[2]==board[8])){
            if(board[2]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[0]==board[4]) && (board[0]==board[8])){
            if(board[0]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
        else if((board[2]==board[4]) && (board[2]==board[6])){
            if(board[6]==0){
                this->winner = 0;
            }
            else{
                this->winner = 1;
            }
        }
    }

    void playsMove(int row, int col, int player) {
        int move = convertMove(row, col, size);
        int* board = this->board;

        cout << "How big it is now, somehow... " <<  this->size << endl;
        cout << "gameobj.h:103" <<endl;
        if (move >= 0 && move < this->size * this->size) {
            board[move] = player;       
            this->board = board;
        } else {
            cout << "Invalid move." << endl;
        }
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
    subGame** subgamesPtr; // pointer to array
    bool* playable;
    int* subWinners;
    bool gameOver;
    int winner;

public: 
    void init(int size) {
        this->size = size;
        subGame* newSubgames = new subGame[size * size];
        this->playable = new bool[size * size];
        this->subWinners = new int[size * size];
        this->subgamesPtr = new subGame*[size * size];
        this->winner = -1;
        this->gameOver = false;

        std::fill_n(this->playable, size * size, true);
        std::fill_n(this->subWinners, size * size, -1);

        for (int i = 0; i < size * size; i++) {
            subgamesPtr[i] = &newSubgames[i];
            // subgamesPtr[i]->init(size*size);
            (*subgamesPtr)[i].init(size*size);     
        }

        cout << "Now to see if it's stored in the Game object" << endl;
        for(int i = 0; i < size*size; i++){
            cout << (*subgamesPtr)[i].getSize()<<endl;
        }

        cout << "init finished" << endl;
    }

    void playsMove(int row, int col, int player, int board ){
        cout << "playing move" << endl;
        subGame** subgamesptr = this->subgamesPtr;
        for(int i = 0; i < this->size* this->size; i++){
            cout << "Board" << i << "of" << this->size * this->size<< endl;
            cout << "How big the subgame thinks it is..." << (*subgamesPtr)[i].getSize() << endl;
            cout << "Address: "<< &(*subgamesPtr[i]) << endl;
        }
        cout << "Playing board " << board << endl;
        if(board!= -1){
        (*subgamesptr)[board].playsMove(row, col, player);
    } else cout << "invalid board, board cannot be " << board;}
    
    void setOverallWinner(){ //Very not DRY but we deal with it
        size_t size = this->size;
        int* subWinners = this->subWinners;
        int winner = this->winner;
        
        /*
        Win conditions:
        - Someone wins an entire row (subgames[const][var] is all equal for some const and all var < size)
        - Someone wins entire column
        - Someone wins diagonal
        */

        //Entire col
        // [][][] [][][] [][][]
        //  ^      ^      ^
        // idx += size

        for(int col = 0; col < size; col++){
        int playerOneWinCount = 0, playerTwoWinCount = 0; 
            for(int row = 0; row < size; row++){
                int blockWinner = subWinners[row*size+col];
                if(blockWinner == -1) break; //no winner
                if(blockWinner == 0) playerOneWinCount++;
                if(blockWinner == 1) playerTwoWinCount++;
                int winner = playerOneWinCount == size? 0: 1;
                this->gameOver = true;
            }
       }

        //Entire row
        // [][][] [][][] [][][]
        //  ^ ^ ^
        // idx++
        for(int col = 0; col < size; col++){
            int playerOneWinCount = 0, playerTwoWinCount = 0; 
            for(int row = 0; row < size; row++){
                int blockWinner = subWinners[col*size + row];
                if(blockWinner == -1) break; //no winner
                if(blockWinner == 0) playerOneWinCount++; 
                if(blockWinner == 1) playerTwoWinCount++;
                int winner = playerOneWinCount == size? 0:1;
                this->gameOver = true;
            }
        }

        //Diagonal
        //[][][] [][][] [][][]
        // ^        ^        ^
        //idx += size+1 && idx starts at 0
        for(int idx = 0; idx < size*size; idx += size+1){  
            int playerOneWinCount = 0, playerTwoWinCount = 0; 
            int blockWinner = subWinners[idx];
            if(blockWinner == -1) break; //no winner
            if(blockWinner == 0) playerOneWinCount++; 
            if(blockWinner == 1) playerTwoWinCount++;
            int winner = playerOneWinCount == size? 0:1;
            this->gameOver = true;

        }

        //Diagonal, vol. 2
        //[][][]  [][][]  [][][]
        //     ^     ^     ^
        //idx += size-1 && idx starts at size

        for(int idx = size; idx < size*size; idx += size-1){
            int playerOneWinCount = 0, playerTwoWinCount = 0; 
            int blockWinner = subWinners[idx];
            if(blockWinner == -1) break; //no winner
            if(blockWinner == 0) playerOneWinCount++; 
            if(blockWinner == 1) playerTwoWinCount++;
            int winner = playerOneWinCount == size? 0:1;
            this->gameOver = false;
        }
        

    }

    subGame** getSubgamesPtr(){
        return this->subgamesPtr;
    }

    int getSize(){
        return this->size;
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
        setOverallWinner();
          
    }
 void print() {
    subGame** tempGamePtr = this->subgamesPtr;
    for(int i=0; i<this->size; i++){
        for(int j=0; j<this->size; j++){
            //int convertedMove = row*size + col;
            for(int k=0; k<this->size; k++){
                int boardPosition = j*this->size + k;
                //cout << tempPtr[i][boardPosition] << " ";
                cout << (*tempGamePtr)[i].getBoard()[boardPosition];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
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

    //Hannah's work
};
}

#endif