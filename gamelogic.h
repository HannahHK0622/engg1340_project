
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
int convertMove(int row, int col, int size);
int chooseBoard(int* lastPlay, size_t size);
int* getDefaultLastPlay();
int* takeMove(bool freeBoardChoice);
bool checkInput(int* input, bool freeBoardChoice);

#endif