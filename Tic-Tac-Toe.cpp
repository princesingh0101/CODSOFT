#include <iostream>
#include <vector>
#include <string>
#include <limits>

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    std::cout << "     1   2   3\n";
    std::cout << "   -------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << " " << i + 1 << " | ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n";
        std::cout << "   -------------\n";
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Welcome to Tic-Tac-Toe! Let's have some fun!\n";

    std::string playAgainChoice;

    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameEnded = false;

        std::cout << "\nAlright, Player X, you're up first! Player O, get ready for your turn!\n";

        while (!gameEnded) {
            displayBoard(board);

            int row, col;
            bool validInput = false;

            while (!validInput) {
                std::cout << "Player " << currentPlayer << ", where would you like to place your mark? (Enter row and column, like '1 2' for top-middle): ";
                
                if (!(std::cin >> row >> col)) {
                    std::cout << "Oh no! That doesn't look like a valid spot. Please enter two numbers (row then column).\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
                    if (board[row - 1][col - 1] == ' ') {
                        validInput = true;
                    } else {
                        std::cout << "Hmm, that space is already taken! Please pick an empty one.\n";
                    }
                } else {
                    std::cout << "Whoops! Those coordinates are off the board. Remember, rows and columns are between 1 and 3.\n";
                }
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "YES! Player " << currentPlayer << " has won the game! What a fantastic play! Congratulations!\n";
                gameEnded = true;
            }
            else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a tie! The board is full, and neither player won. A truly balanced match! Well played, both of you!\n";
                gameEnded = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        std::cout << "Fancy another round? (Type 'yes' or 'no'): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, playAgainChoice);

    } while (playAgainChoice == "yes" || playAgainChoice == "y" || playAgainChoice == "Yes" || playAgainChoice == "Y");

    std::cout << "Thanks for playing Tic-Tac-Toe with me! Hope to see you again soon!\n";

    return 0;
}
