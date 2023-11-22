#include <iostream>
#include <string>
#include "gamelogic.h"


using namespace std;
using namespace GameObj;

int convertMove(int row, int col, int size){
    int convertedMove;
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
    
    return board;
}

int* getDefaultLastPlay(){
    //Gets the default value
    int row=-1, col=-1; //{-1, -1} should be impossible, but it still fits int* so I guess?
    int defaultValue[] = {row, col};
    return defaultValue;
}

int* takeMove(bool freeBoardChoice){
    int row, col;
    if(freeBoardChoice){
        int boardRow, boardCol;
        cout << "You may choose which board to play this time." << endl;
        cin >> boardRow >> boardCol;
        cout << endl;
        cout << "Input the row, then the column that you'd like to play in, separated by space." << endl;
        cin >> row >> col;
        int returnVal[] = {row, col, boardRow, boardCol};
        return returnVal;
    } else {
        cout << "Input the row, then the column that you'd like to play in, separated by space." << endl;
        cin >> row >> col;
        int returnVal[] = {row, col};
        return returnVal;
    }
}

bool checkInput(int* input, bool freeBoardChoice){
    bool isValid;
    //Logic here to validate input

    return isValid;
}


/*
[][][x] row 0 col 2
[][][]
[][][]


[][][x][][][][][][] board[2]
*/
    