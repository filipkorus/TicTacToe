#include <iostream>
#include "TicTacToe.h"

int main() {

   char newGame;
   do {
      auto game = new TicTacToe;
      char winner;
      do {
         game->printBoard()->menu();
         winner = game->checkWin();
      } while(winner == ' ');

      game->printBoard();
      std::cout << '\n' << (winner == 'd' ? "it's a draw!\n" : winner + " won the game!\n");
      std::cout << "\nWould you like to start new game? (y/n): ";
      std::cin >> newGame;
   } while(newGame == 'y');

   return 0;
}