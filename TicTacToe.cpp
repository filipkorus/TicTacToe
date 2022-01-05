#include "TicTacToe.h"

bool TicTacToe::isPosTaken(std::string coordinates, bool displayMsg = true) {
   int x = 3 - 1 - (int(coordinates[1]) - int('0') - 1);
   int y = int(coordinates[0]) - int('A');
   if (x < 0 || y < 0 || x > 3 - 1 || y > 3 - 1) {
      if (displayMsg) std::cout << "Incorrect coordinates!";
      return true;
   }
   bool result = (matrix[x][y] != ' ');
   if (result && displayMsg) std::cout << "This place is already taken!";
   return result;
}

TicTacToe *TicTacToe::setPos(std::string coordinates) {
   int x = 3 - 1 - (int(coordinates[1]) - int('0') - 1);
   int y = int(coordinates[0]) - int('A');
   this->matrix[x][y] = this->player;
   return this;
}

TicTacToe *TicTacToe::togglePLayer() {
   this->player = (this->player == 'x') ? 'o' : 'x';
   return this;
}

TicTacToe::TicTacToe() {
   // init matrix size
   this->matrix = new char *[3];
   for (int i = 0; i < 3; ++i) {
      this->matrix[i] = new char[3];
      for (int j = 0; j < 3; j++) this->matrix[i][j] = ' ';
   }
}

TicTacToe::~TicTacToe() {
   for (int i = 0; i < 3; i++) delete this->matrix[i];
   delete this->matrix;
}

TicTacToe *TicTacToe::printBoard() {
   std::cout << "\n  ";
   for (int i = 0; i < 3; i++) std::cout << char('A' + i) << ' ';
   std::cout << '\n';
   for (int i = 0; i < 3; i++) {
      std::cout << 3 - i << ' ';
      for (int j = 0; j < 3; j++) std::cout << this->matrix[i][j] << ((j == 3 - 1) ? ' ' : '|');
      std::cout << 3 - i << '\n';
   }
   std::cout << "  ";
   for (int i = 0; i < 3; i++) std::cout << char('A' + i) << ' ';
   return this;
}

char TicTacToe::checkWin() {
   if (this->matrix[0][0] != ' ' && this->matrix[0][0] == this->matrix[0][1] && this->matrix[0][1] == this->matrix[0][2]) return this->matrix[0][0];
   if (this->matrix[1][0] != ' ' && this->matrix[1][0] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[1][2]) return this->matrix[1][0];
   if (this->matrix[2][0] != ' ' && this->matrix[2][0] == this->matrix[2][1] && this->matrix[2][1] == this->matrix[2][2]) return this->matrix[2][0];

   if (this->matrix[0][0] != ' ' && this->matrix[0][0] == this->matrix[1][0] && this->matrix[1][0] == this->matrix[2][0]) return this->matrix[0][0];
   if (this->matrix[0][1] != ' ' && this->matrix[0][1] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[2][1]) return this->matrix[0][1];
   if (this->matrix[0][2] != ' ' && this->matrix[0][2] == this->matrix[1][2] && this->matrix[1][2] == this->matrix[2][2]) return this->matrix[0][2];

   if (this->matrix[0][0] != ' ' && this->matrix[0][0] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[2][2]) return this->matrix[0][0];
   if (this->matrix[0][2] != ' ' && this->matrix[0][2] == this->matrix[1][1] && this->matrix[1][1] == this->matrix[2][0]) return this->matrix[0][2];

   bool draw = true;
   for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
         if (this->matrix[i][j] == ' ')
            draw = false;

   return draw ? 'd' : ' ';
}

TicTacToe *TicTacToe::menu() {
   std::cout << "\nCurrent turn: " << this->player;
   std::string coordinates;
   do {
      std::cout << "\nInsert coordinates of place you want to mark: ";
      std::cin >> coordinates;
      coordinates[0] = toupper(coordinates[0]);
      coordinates[1] = toupper(coordinates[1]);
   } while(TicTacToe::isPosTaken(coordinates));

   TicTacToe::setPos(coordinates)->TicTacToe::togglePLayer();
}
