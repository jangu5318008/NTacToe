#include <iostream>
#include "TextGraphics.h"

using namespace std;

const int N = 10;
void initBoard(char board[N][N], int n);
void printBoard(char board[N][N], int n);
bool isGameOver(char board[N][N], int n);
void getPlayerInput(char board[N][N], int n, char playerChar);

int main() {

    TextGraphics graphics;  

    char board[N][N];
    cout << "How big of a board do you want?";
    int n; 
    cin >> n;

    initBoard(board, n); 
    printBoard(board, n);
    while (!isGameOver(board,n)) {
        //
    }
void initBoard(char board [N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
    cout << '\n';
}
}
bool isGameOver(char board[N][N], int n) {



    return false;
}






return 0;
}
