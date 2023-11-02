#include <iostream>
#include <vector>
#include <string>

using namespace std;
class subGame{
    int size;
    int board[];
    int subGameWinner;

}

class Game: public subGame{
    int size;
    subGame subgames[];
    int overallWinner;
}



int main(){

    return 0;
}