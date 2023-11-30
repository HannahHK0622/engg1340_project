#include <iostream>
#include <string>
#include <vector>
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

    if(isPlayable == true
        || lastRow < size
        || lastCol < size){
        board = board;
    }
    else{
        board = -1;
    }

    
    return board;
}

vector<int> getDefaultLastPlay(){
    //Gets the default value
    int row=-1, col=-1; //{-1, -1} should be impossible, but it still fits int* so I guess?
    vector<int> returnVal = {row, col};
    return returnVal;
}

vector<int> takeMove(){
    int row, col;
    int boardRow, boardCol;
    // cout << "You may choose which board to play this time." << endl;
    cout << "Enter the row and column of the board you'd like to play in, separated by space." << endl;
    cin >> boardRow >> boardCol;
    cout << endl;
    cout << "Input the row, then the column that you'd like to play in, separated by space." << endl;
    cin >> row >> col;
    vector<int> returnVal = {row--, col--, boardRow--, boardCol--};
    return returnVal;
}

bool checkInput(vector<int> input, Game& game) {
    bool isValid;
    int size = game.getSize();
    int boardIndex1d = input[2] * size + input[3];

    if (game.getPlayable()[boardIndex1d] == false || boardIndex1d >= size * size) {
        isValid = false;
    } else {
        int subBoardIndex1d = input[0] * size + input[1];
        subGame** subgamePtr = game.getSubgamesPtr();
        cout << "Checking if the selected space is playable..." << endl;

        subGame* subgame = subgamePtr[boardIndex1d];
        int* subBoard = subgame->getBoard();
        cout << "obtained board contents of subgame " << boardIndex1d << endl;
        for(int i = 0; i < size*size; i++) cout << subBoard[i] << endl;
        if (subBoard[subBoardIndex1d] == -1) {
            isValid = true;
        } else {
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
    