#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if the game is won
char checkWin(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    return ' ';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.')); // Initialize empty board

    int row, col;
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1: X, Player 2: O" << endl;

    while (!gameOver) {
        printBoard(board);

        // Get player input
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '.') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check if the game is won
        char winner = checkWin(board);
        if (winner != ' ') {
            printBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            gameOver = true;
        } else {
            // Check for a draw
            bool draw = true;
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == '.') {
                        draw = false;
                        break;
                    }
                }
                if (!draw) break;
            }
            if (draw) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}
