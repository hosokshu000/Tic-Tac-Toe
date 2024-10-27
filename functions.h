#include <iostream>
#include <vector>
#include <type_traits>

void greet();
void printBoard(std::vector<std::string> board);
std::pair<int, int> getTurn(std::string team);
bool validTurn(std::vector<std::string> board, std::pair<int, int> coords);
std::vector<std::string> editBoard(std::vector<std::string> board, std::pair<int, int> coords, std::string team);
bool checkWin(std::vector<std::string> board);
template <typename T>
bool isInteger(T value) {
    return std::is_integral<T>::value;
}
