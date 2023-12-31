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


int chooseBoard(size_t size, Game& game, int board){

    bool isPlayable = (game.getPlayable())[board];

    if(isPlayable == true){
        board = board;
    }
    else{
        board = -1;
    }

    
    return board;
}


vector<int> takeMove(){
    int row, col;
    int boardRow, boardCol;
    // cout << "You may choose which board to play this time." << endl;
    cout << "0, 0 is the top left corner." << endl;
    cout << "Enter the row and column of the board you'd like to play in, separated by space." << endl;
    cin >> boardRow >> boardCol;
    cout << endl;
    cout << "Input the row, then the column that you'd like to play in, separated by space." << endl;
    cin >> row >> col;
    vector<int> returnVal = {row, col, boardRow, boardCol};
    return returnVal;
}

bool checkInput(vector<int> input, Game& game) {
    //input = {row, col, boardRow, boardCol}
    bool isValid;
    int size = game.getSize();
    int subBoardIDX = input[0] * size + input[1];
    int boardIndex1d = input[2] * size + input[3];

    cout << size << endl;
    //A valid input...
    if(
    //Points to a board that exists and is playable, and
    (0 <= boardIndex1d < size*size && game.getPlayable()[boardIndex1d] == true &&
    //Points to a space that exists and is open
     0 <= subBoardIDX < size*size && (game.getSubgamesPtr())[boardIndex1d]->getBoard()[subBoardIDX] == -1
    )) // then it must be valid. 
    isValid = true;

    else isValid = false;
    // if (game.getPlayable()[boardIndex1d] == false || boardIndex1d >= size * size) {
    //     isValid = false;
    // } else {
    //     int subBoardIndex1d = input[0] * size + input[1];
    //     subGame** subgamePtr = game.getSubgamesPtr();
    //     cout << "Checking if the selected space is playable..." << endl;

    //     subGame* subgame = subgamePtr[boardIndex1d];
    //     int* subBoard = subgame->getBoard();
    //     if (subBoard[subBoardIndex1d] == -1) {
    //         isValid = true;
    //     } else {
    //         isValid = false;
    //     }
    // }

    return isValid;
}


/*
[][][x] row 0 col 2
[][][]
[][][]


[][][x][][][][][][] board[2]
*/
    