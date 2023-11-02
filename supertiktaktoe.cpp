#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int[9]> getBoard(){//Defined so that it can be collapsed
    vector<int[9]> board = {
        {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},
         
         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0},

         {0, 0, 0,
         0, 0, 0,
         0, 0, 0}
    }; 
    return board;
}

void format(vector<int[9]>* game){
    
}

int* takeInput(){
    int inputs[2];
    return inputs;
}

int* takeInput(int* lastInput){ //Overload to take last input

}

vector<int[9]> makePlay(vector<int[9]>* game, int[2]& play){
    return game;
}

int* getGameState(vector<int[9]>* game){
    int[3] gameState;
    return gameState;
}

int main(int argc, char** argv){
    //Initialisation
    bool endGame = false;
    string* players[2];
    cout << "Please type the name of Player 1";
    cin >> players[0];
    cout << endl << "Please type the name of Player 2";
    cin >> players[1];
    cout << endl;

    //Initial play
    vector<int[9]> game = getBoard();
    format(game);
    int play = takeInput();
    vector<int[9]> game = makePlay(&game, play)
    
    //While loop for normal gameplay
    while(endGame == false){
        format(game);
        int play[] = takeInput(play);
        vector<int[9]> game = makePlay(&game, play);
        int* gameState = getGameState(&game);
    }
    int winner = gameState[1];
    cout << winner << " has won the game!" << endl;
    return 0;
}