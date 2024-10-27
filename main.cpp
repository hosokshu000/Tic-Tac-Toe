#include <iostream>
#include <vector>
#include "functions.h"


int main() {
  greet();

  std::vector<std::string> board = {"   1   2   3   ", "1    |   |   ", "  -----------", "2    |   |   ", "  -----------", "3    |   |   "};
  std::vector<std::string> teams = {"Circle", "Cross"};
  std::pair<int, int> coords;
  std::string currentTeam;
  bool win = false;
  int cnt = 0;

  while (cnt < 9 && !win) {
    printBoard(board);
    currentTeam = teams[cnt % 2];
    coords = getTurn(currentTeam);

    while(!validTurn(board, coords)) {
      std::cout << "\nPlease enter a valid coordinate.\n";
      printBoard(board);
      coords = getTurn(currentTeam);
    }

    board = editBoard(board, coords, currentTeam);
    win = checkWin(board);
    cnt++;
  }

  printBoard(board);

  if(win) {
    std::cout << "\n" << currentTeam << " wins!" << std::endl;
  }
  else {
    std::cout << "\nDraw.\n";
  }
}
