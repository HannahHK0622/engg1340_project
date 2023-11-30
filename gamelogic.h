
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "gameobj.h"
#include <vector>

using namespace std;
using namespace GameObj;

int convertMove(int row, int col, int size);
int chooseBoard(size_t size, Game& game, int board);
vector<int> takeMove();
bool checkInput(vector<int> input, Game& game);

#endif