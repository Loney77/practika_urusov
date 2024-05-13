#include <iostream>
#include <vector>
#include <cstdlib>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char player;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), player('X') {}

    void drawBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << '|';
            }
            std::cout << "\n";
            if (i < 2) std::cout << "-----\n";
        }
    }

    void makeMove() {
        setlocale(LC_ALL, "RUS");
        int x, y;
        if (player == 'X') {
            std::cout << "Введите координаты хода (строка и столбец): ";
            std::cin >> x >> y;
        }
        else {
            x = rand() % 3;
            y = rand() % 3;
        }
        if (board[x][y] == ' ') {
            board[x][y] = player;
            player = (player == 'X') ? 'O' : 'X';
        }
        else {
            std::cout << "Недопустимый ход. Попробуйте еще раз.\n";
            makeMove();
        }
    }

    bool isGameOver() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return true;
        return false;
    }
};

int main() {
    TicTacToe game;
    while (!game.isGameOver()) {
        game.drawBoard();
        game.makeMove();
    }
    game.drawBoard();
    return 0;
}
