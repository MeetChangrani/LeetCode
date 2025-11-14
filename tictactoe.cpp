#include <iostream>

using namespace std;


void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << "\n";
}


bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void resetBoard(char board[3][3]) {
    char count = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = count++;
        }
    }
}
void playerMove(char board[3][3], char player) {
    int move;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Please enter a number between 1 and 9." << endl;
        } else {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                validMove = true;
            } else {
                cout << "That spot is already taken. Try again." << endl;
            }
        }
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false, draw = false;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard(board);
        gameWon = false;
        draw = false;
        currentPlayer = 'X'; 

        
        while (!gameWon && !draw) {
            displayBoard(board);
            playerMove(board, currentPlayer);
            gameWon = checkWin(board, currentPlayer);
            draw = checkDraw(board);

            if (gameWon) {
                displayBoard(board);
                cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
            } else if (draw) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
            } else {
                
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}
