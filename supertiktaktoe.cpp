#include <iostream>
#include <vector>
#include <string>

using namespace std;
class subGame{
private:
    int size;
    int* board;
    int subGameWinner;

public:
    void init(int size){
        this -> size = size;
        int* board = new int[size * size];
    }
};
class Game: public subGame{
private: 
    int size;
    subGame* subgames;
    int overallWinner;
public: 
    void init(int size, int subGameSize){
        this -> size = size;
        subgames = new subGame[subGameSize * subGameSize];
        for(int i = 0; i < size*size; i++){
            subgames[i].init(subGameSize);
        }
    }
};



int main(){
    cout << "Please enter the names of each player..." << endl;
    string player1, player2;
    cin >> player1 >> player2;
    cout << "At this phase, we are only supporting 3x3x3 super tik tak toe. Stay tuned for more!" << endl;
    Game game;
    game.init(3, 3)
    return 0;
}