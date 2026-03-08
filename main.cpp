#include <iostream>


using namespace std;

const int N = 10;
void initBoard(char board[N][N], int n);
void printBoard(char board[N][N], int n);
bool isGameOver(char board[N][N], int n);
void getPlayerInput(char board[N][N], int n, char playerChar);

void initBoard(char board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '_';
        }
    }
}
//////////MAIN GAME LOGIC///////////
bool isGameOver(char board[N][N], int n) {
    for (int row = 0; row < n; row++) {
        char winner = board[row][0]; 
        if (winner == '_') {
            continue;
        }

        bool rowWin = true; 
        for (int col = 1; col < n; col++) {
            if (board[row][col] != winner) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) {
            cout << "Player " << winner << " wins! Now wasn't that fun?\n"; 
            return true;
        }
    }
    for (int col = 0; col < n; col++) {
        char winner = board[0][col];
        if (winner == '_') {
            continue; 
        }

        bool colWin = true;
        for (int row = 1; row < n; row++) {
            if (board[row][col] != winner) {
            colWin = false; 
            break;
            }
        }

    
    if (colWin) {
        cout << "Player " << winner << " wins! Now wasn't that fun?\n"; 
        return true;
    }
}
    char forwardWinner = board[0][0];
    if (forwardWinner != '_') {
        bool forwardWin = true;
        for (int i = 1; i < n; i++) {
            if (board[i][i] != forwardWinner) {
                forwardWin = false;
                break;
            }
        }
        if (forwardWin) {
            cout << "Player " << forwardWinner << " wins! Now wasn't that fun?\n";
            //play again
            return true;
        }
    }
    char backwardWinner = board[0][n - 1]; 
    if (backwardWinner != '_') {
        bool backwardWin = true; 
        for (int row = 1; row < n; row++) {
            int col = n - row - 1; 
            if (board[row][col] != backwardWinner) {
                backwardWin = false; 
                break;
            }
        }
        if (backwardWin) {
            cout << "Player " << backwardWinner << " wins! Now wasn't that fun?\n";
            //play again
            return true;
        }
    }

    bool boardFull = true;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == '_') {
                boardFull = false; 
                break;
            }
        }
        if (!boardFull) {
            break;
        }
    }
    if (boardFull) {
        cout << "It's a draw!\n";
        return true;
    }


    return false;
}




void printBoard(char board[N][N], int n) {
    cout << "\n   ";
    for (int col = 1; col <=n; col++) {
        cout << col << ' ';
    }
    cout << "\n";

    for (int row = 0; row < n; row++) {
        cout << (row + 1) << ": ";
        for (int col = 0; col < n; col++) {
            cout << board[row][col] << ' ';
        }
        cout << '\n';
    }
}

void getPlayerInput(char board[N][N], int n, char playerChar) {
    int row, col, rowInput, colInput;
    do {
        do {
            cout << "Player " << playerChar << ", enter row [1:" << n << "]: ";
            cin >> rowInput;
        } while (rowInput < 1 || rowInput > n);
        do {
            cout << "Player " << playerChar << ", enter column [1:" << n << "]: ";
            cin >> colInput;
        } while (colInput < 1 || colInput > n);
        row = rowInput - 1; 
        col = colInput - 1; 
    if (board[row][col] != '_') {
        cout << "Space already taken. Pick another spot.\n";
    }
} while (board[row][col] != '_');
  board[row][col] = playerChar;
}




int main() {


    int n; 
    char board[N][N];
  
   
    cout << "How big of a board do you want? ";
    cin >> n;


    while (n < 3 || n > 10) {
        cout << "Invalid. Enter a size from 3 to 10: " ; 
        cin >> n;
    }
    initBoard(board, n); 
    printBoard(board, n);

    char playerChar = 'X';

    while (!isGameOver(board, n)) {
        getPlayerInput(board, n, playerChar); 
        printBoard(board, n); 
        if (playerChar == 'X') {
            playerChar = 'O';
        } 
        else {
            playerChar = 'X';
        }
    }

return 0;
}
