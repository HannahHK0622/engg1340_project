#include <iostream>
#include <string>
#include "gamelogic.h"
#include "gameobj.h"

using namespace std;
using namespace GameObj;

void declareWinner(string winner){
    cout << "The player is " << winner << endl;
}


int main(){
    //Set false for submission
    const bool debugging = false;

    //initialisation
    vector<int> lastPlay = getDefaultLastPlay();
    string player1, player2;
    string players[] = {player1, player2};
    char playerToken[] = {'X', 'O'};
    bool player = 0;
    bool freeBoardChoice;
    size_t size;
    cout << "Please enter the names of player 1 and player 2 respectively." << endl;
    cin >> player1 >> player2;
    cout << "Give one number; This number represents the size of the subGame (for a 3x3 game, enter \"3\")" << endl;
    cin >> size;
    Game game;
    game.init(size);

    //Debug removed from here...

    //Game logic begins here
    while(true){
        game.update();
        int board = chooseBoard(lastPlay[0], lastPlay[1], game.getSize(), game);
        vector<int> input = takeMove();
        bool inputValidity = checkInput(input, game);
        cout << "Input checked." << endl;
        if(inputValidity) game.playsMove(input[1], input[2], player, board);
        else cout << "invalid move. Forfeit 1 round." << endl;
        game.update();
        game.print();
        if(game.getGameOver()){
            break;
        }
        player = !player;
    }

    //game over block   
    declareWinner(players[game.getWinner()]);
    game.destruct();
    return 0;
}



