
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "gameobj.h"

using namespace std;
using namespace GameObj;

int convertMove(int row, int col, int size);
int chooseBoard(int lastRow, int lastCol, size_t size, GameObj::Game game);
int* getDefaultLastPlay();
int* takeMove();
bool checkInput(int* input, Game& game);

#endif