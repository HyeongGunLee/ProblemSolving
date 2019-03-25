#include <iostream>
#include <cstdio>
using namespace std;

int T;
int N;
int board[101][101];
int result[101][101];

void initBoard() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            board[i][j] = -1;
            result[i][j] = 0;
        }
    }
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void printResult() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int findMinPath() {
    // return minPath to the end
    // start = (0, 0), end = (N-1, N-1)
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (row == 0 && col == 0) {
                continue;
            } else if (row == 0) {
                result[row][col] = result[row][col-1] + board[row][col];
            } else if (col == 0) {
                result[row][col] = result[row-1][col] + board[row][col];
            } else {
                result[row][col] = min(result[row-1][col], result[row][col-1]) + board[row][col];
            }
        }
    }

    return result[N-1][N-1];
}

int main(void) {
    cin >> T;
    for (int x = 0; x < T; x++) {
        cin >> N;
        initBoard();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &board[i][j]);
            }
        }
        cout << "-----------------LOGGING-----------------" << endl;
        printBoard();
        cout << endl;
        printResult();
        // find MinPAth
        cout << "-----------------RESULT------------------" << endl;
        cout << "#" << x+1 << " " << findMinPath() << endl;

    }

}
