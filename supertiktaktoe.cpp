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
        vector<int> input = takeMove();
        cout << "It's the turn of player: " << player << endl;
        int board = chooseBoard(size, game, convertMove(input[2], input[3], size));
        bool inputValidity = checkInput(input, game);
        cout << "Input checked." << endl;
        if(inputValidity) game.playsMove(input[0], input[1], player, board);
        else cout << "invalid move. Forfeit 1 round." << endl;
        game.update();
        game.print();
        player = !player;
        if(game.getGameOver()){
            break;
        }
        //Since there are two players, then player++ mod 2 for player = 0 is 1 and for player = 1 is 0.
    }

    //game over block   
    declareWinner(players[game.getWinner()]);
    game.destruct();
    return 0;
}



