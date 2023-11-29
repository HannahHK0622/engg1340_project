#include <iostream>
#include <string>
#include "gamelogic.h"


using namespace std;
using namespace GameObj;

int convertMove(int row, int col, int size){
    //For a board of size "size", there are size^2 slots.
    //Unrelated, but maybe there's a way to express that:
    //1d coordinate = row*size + col?
    //2d to 1d
    int convertedMove = row*size + col;
    return convertedMove;

    //Jintao's work
    }


int chooseBoard(int lastRow, int lastCol, size_t size, Game game){
    int board;
    //a bunch of logic
    //accoring to lastRow, lastCol, choose a board
    //Also check if it's playable
    //If the board is unplayable, return -1
    board = lastRow*size + lastCol;
    bool isPlayable = (game.getPlayable())[board];

    if(isPlayable == true){
        board = board;
    }
    else{
        board = -1;
    }

    
    return board;
}

int* getDefaultLastPlay(){
    //Gets the default value
    int row=-1, col=-1; //{-1, -1} should be impossible, but it still fits int* so I guess?
    int defaultValue[] = {row, col};
    return defaultValue;
}

int* takeMove(){
    int row, col;
    int boardRow, boardCol;
    cout << "You may choose which board to play this time." << endl;
    cin >> boardRow >> boardCol;
    cout << endl;
    cout << "Input the row, then the column that you'd like to play in, separated by space." << endl;
    cin >> row >> col;
    int returnVal[] = {row, col, boardRow, boardCol};
    return returnVal;
}

bool checkInput(int* input, Game& game){
    bool isValid;
    //Logic here to validate input
    //int convertedMove = row*size + col;
    int boardIndex1d = input[2]*(game.getSize()) + input[3];
    if((game.getPlayable())[boardIndex1d] == false){
        isValid = false;
    }
    else{
        int subBoardIndex1d = input[0]*(game.getSize()) + input[1];
        if(*(game.getSubgamesPtr())[boardIndex1d][subBoardIndex1d] == false){ //Don't know the initial value of array
            isValid = true;
        }
        else{
            isValid = false;
        }
    }
    
    return isValid;
}


/*
[][][x] row 0 col 2
[][][]
[][][]


[][][x][][][][][][] board[2]
*/
    