#include <iostream>
#include <string>
#include "gamelogic.h"
#include "gameobj.h"

using namespace std;
using namespace GameObj;

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}

void debug(Game game){
    cout << "debug active" << endl;
    //Debug stuff goes here and please PLEASE delete before deadline
    game.rawDump();
}

int main(){
    //Set false for submission
    const bool debugging = true;

    //initialisation
    int* lastPlay = getDefaultLastPlay();
    string player1, player2;
    string players[] = {player1, player2};
    char playerToken[] = {'X', 'O'};
    bool player = 0;
    bool freeBoardChoice;
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
        game.update();
        int board = chooseBoard(lastPlay[0], lastPlay[1], game.getSize(), game);
        freeBoardChoice = board == -1;
        int* input = takeMove();
        bool inputValidity = checkInput(input, game);
        if(game.getGameOver()){
            break;
        }
    }

    //game over block   
    declareWinner(players[game.getWinner()]);
    game.destruct();
    return 0;
}



