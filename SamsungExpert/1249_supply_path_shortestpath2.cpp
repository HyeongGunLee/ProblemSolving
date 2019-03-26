#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int T, N;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int board[101][101];


struct iPair{
    int x, y;
    iPair(int x, int y) : x(x), y(y) {};
} ;

void initBoard() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            board[i][j] = 0;
        }
    }
}

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        return true;
    }
    return false;
}

int shortestPath() {
    int d[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = -1;
        }
    }

    queue<iPair> q;
    q.push(iPair(0, 0));
    d[0][0] = board[0][0];


    while(!q.empty()) {
        iPair temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = temp.x + direction[i][0];
            int ny = temp.y + direction[i][1];

            if (isInside(nx, ny)) {
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[temp.x][temp.y] + board[nx][ny];
                    q.push(iPair(nx, ny));
                } else {
                    if (d[nx][ny] > d[temp.x][temp.y] + board[nx][ny]) {
                        d[nx][ny] = d[temp.x][temp.y] + board[nx][ny];
                        q.push(iPair(nx, ny));
                    }
                }
            }
        }
    }
    return d[N-1][N-1];
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
//        printBoard();
        cout << "#" << x+1 << " " << shortestPath() << endl;
    }
}
