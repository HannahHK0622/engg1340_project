
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "gameobj.h"
#include <vector>

using namespace std;
using namespace GameObj;

int convertMove(int row, int col, int size);
int chooseBoard(int lastRow, int lastCol, size_t size, GameObj::Game game);
vector<int> getDefaultLastPlay();
vector<int> takeMove();
bool checkInput(vector<int> input, Game& game);

#endif