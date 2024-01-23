#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there is an empty space, the game is not a draw yet
            }
        }
    }
    return true; // All cells are filled, and no player has won, so it's a draw
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Display the current state of the board
        printBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3): ";
        cin >> row >> col;
        row--; // Adjust to 0-based index
        col--;

        // Update the board with the player's move
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                // Display the final state of the board
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for draw
            if (checkDraw(board)) {
                // Display the final state of the board
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players for the next turn
            currentPlayer = switchPlayer(currentPlayer);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board for a new game
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    } else {
        cout << "Thanks for playing! Goodbye." << endl;
    }

    return 0;
}
