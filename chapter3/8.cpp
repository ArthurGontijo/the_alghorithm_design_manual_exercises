/* ------------- Problem 3-8 -------------
Tic-tac-toe is a game played on an n × n board (typically n = 3) where two players take consecutive
turns placing “O” and “X” marks onto the board cells.  The game is won if n consecutive “O” or ‘X”
marks are placed in a row, column, or diagonal. Create a data structure with O(n) space that
accepts a sequence of moves, and reports in constant time whether the last move won the game.
*/
#include <iostream>
#include <vector>

class Board {
  private:
    int n;
    std::vector<int> row;
    std::vector<int> col;
    int diagonal;
    int antiDiagonal;

  public:
    // Space of O(2n + 2) = O(n), so linear space complexity
    Board(int boardSize)
        : n(boardSize), row(boardSize, 0), col(boardSize, 0), diagonal(0), antiDiagonal(0) {}

    bool hasMoveWon(int mark, int x, int y) {
        int markValue = mark == 'O' ? 1 : -1;

        return (row[x] == markValue * n) || (col[y] == markValue * n) ||
               (diagonal == markValue * n) || (antiDiagonal == markValue * n);
    }

    void placeMark(char mark, int x, int y) {
        int markValue = mark == 'O' ? 1 : -1;
        row[y] += markValue;
        col[x] += markValue;
        if (x == y) {
            diagonal += markValue;
        }
        if (x + y == n - 1) {
            antiDiagonal += markValue;
        }
    }
};

int main() {
    int n = 3;
    Board game(n);

    game.placeMark('O', 0, 0);
    std::cout << "O moved (0,0) -> win? " << game.hasMoveWon('O', 0, 0) << "\n";

    game.placeMark('X', 1, 0);
    std::cout << "X moved (1,0) -> win? " << game.hasMoveWon('X', 1, 0) << "\n";

    game.placeMark('O', 1, 1);
    std::cout << "O moved (1,1) -> win? " << game.hasMoveWon('O', 1, 1) << "\n";

    game.placeMark('X', 2, 0);
    std::cout << "X moved (2,0) -> win? " << game.hasMoveWon('X', 2, 0) << "\n";

    game.placeMark('O', 2, 2);
    std::cout << "O moved (2,2) -> win? " << game.hasMoveWon('O', 2, 2) << "\n";

    return 0;
}