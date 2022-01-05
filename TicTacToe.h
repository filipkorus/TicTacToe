#ifndef PI_2021_TICTACTOE_H
#define PI_2021_TICTACTOE_H

#include <iostream>

class TicTacToe {
private:
   char** matrix;
   char player = 'o';
private:
   bool isPosTaken(std::string, bool);
   TicTacToe *setPos(std::string);
   TicTacToe *togglePLayer();
public:
   TicTacToe();
   ~TicTacToe();
   TicTacToe *printBoard();
   char checkWin();
   TicTacToe *menu();
};

#endif //PI_2021_TICTACTOE_H
