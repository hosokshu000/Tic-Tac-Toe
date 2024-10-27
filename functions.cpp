#include <iostream>
#include <vector>
#include <type_traits>
#include <limits>

void greet() {
  std::cout << "\nWelcome to Tic-Tac-Toe!\nBoth player's objective is to get 3 of their symbol in a row.\n";
}

void printBoard(std::vector<std::string> board) {
  std::cout << "\n";
  for (int i = 0; i < board.size(); i++) {
    std::cout << board[i] << std::endl;
  }
  std::cout << "\n";
}

template <typename T>
bool isInteger(T value) {
    return std::is_integral<T>::value;
}

std::pair<int, int> getTurn(std::string team) {
  std::pair<int, int> coords;

  std::cout << "\n" << team << ", enter your row and column for where you want to place your symbol.\n";

  while (true) {
    std::cout << "\nEnter row: ";
    std::cin >> coords.first;
    
    if (std::cin.fail() || !(coords.first >= 1 && coords.first <= 3)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nPlease enter a valid row: " << std::endl;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

  while (true) {
    std::cout << "\nEnter column: ";
    std::cin >> coords.second;
    
    if (std::cin.fail() || !(coords.second >= 1 && coords.second <= 3)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nPlease enter a valid column: " << std::endl;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

  return coords;
}

bool validTurn(std::vector<std::string> board, std::pair<int, int> coords) {
  return board[2 * coords.first - 1][4 * coords.second - 1] == ' '; 
}

std::vector<std::string> editBoard(std::vector<std::string> board, std::pair<int, int> coords, std::string team) {
  char symbol;

  if (team == "Circle") {
    symbol = 'O';
  }
  else {
    symbol = 'X';
  }

  board[2 * coords.first - 1][4 * coords.second - 1] = symbol;
  return board;
}

bool checkWin(std::vector<std::string> board) {
  std::vector<std::pair<int, int>> grid = {{1, 3}, {1, 7}, {1, 11}, {3, 3}, {3, 7}, {3, 11}, {5, 3}, {5, 7}, {5, 11}};

  std::pair<int, int> one = grid[0];
  std::pair<int, int> two = grid[1];
  std::pair<int, int> three = grid[2];
  std::pair<int, int> four = grid[3];
  std::pair<int, int> five = grid[4];
  std::pair<int, int> six = grid[5];
  std::pair<int, int> seven = grid[6];
  std::pair<int, int> eight = grid[7];
  std::pair<int, int> nine = grid[8];

  if (board[one.first][one.second] != ' ' && board[one.first][one.second] == board[two.first][two.second] && board[two.first][two.second] == board[three.first][three.second]) {
    return true;
  }
  if (board[four.first][four.second] != ' ' && board[four.first][four.second] == board[five.first][five.second] && board[five.first][five.second] == board[six.first][six.second]) {
    return true;
  }
  if (board[seven.first][seven.second] != ' ' && board[seven.first][seven.second] == board[eight.first][eight.second] && board[eight.first][eight.second] == board[nine.first][nine.second]) {
    return true;
  }
  if (board[one.first][one.second] != ' ' && board[one.first][one.second] == board[four.first][four.second] && board[four.first][four.second] == board[seven.first][seven.second]) {
    return true;
  }
  if (board[two.first][two.second] != ' ' && board[two.first][two.second] == board[five.first][five.second] && board[five.first][five.second] == board[eight.first][eight.second]) {
    return true;
  }
  if (board[three.first][three.second] != ' ' && board[three.first][three.second] == board[six.first][six.second] && board[six.first][six.second] == board[nine.first][nine.second]) {
    return true;
  }
  if (board[one.first][one.second] != ' ' && board[one.first][one.second] == board[five.first][five.second] && board[five.first][five.second] == board[nine.first][nine.second]) {
    return true;
  }
  if (board[three.first][three.second] != ' ' && board[three.first][three.second] == board[five.first][five.second] && board[five.first][five.second] == board[seven.first][seven.second]) {
    return true;
  }

  return false;
}
