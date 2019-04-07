#include <iostream>
using namespace std;

int N, M;
int board[500][500];
bool visited[500][500] = {0, };
//int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // not work
int direction[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}}; // work
//int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //  work

int maxSum = -1;

bool isInside(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < M) {
        return true;
    }
    return false;
}

void calcMax(int r, int c, int cur, int sum) {
    if (cur == 4) {
        maxSum = max(maxSum, sum);
        return;
    } else if (cur > 4) {
        return;
    }


    for (int i = 0; i < 4; i++) {
        int nr = r + direction[i][1];
        int nc = c + direction[i][0];
        int tr = r + direction[(i+1)%4][0];
        int tc = c + direction[(i+1)%4][1];
        if (isInside(nr, nc) && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            calcMax(nr, nc, cur+1, sum+board[nr][nc]);
            visited[nr][nc] = 0;

            if (isInside(tr, tc) && !visited[tr][tc]) {
                visited[tr][tc] = 1;
                visited[nr][nc] = 1;
                calcMax(nr, nc, cur+2, sum+board[nr][nc]+board[tr][tc]);
                visited[tr][tc] = 0;
                visited[nr][nc] = 0;
            }

        }

    }

}

int getMaxSum() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            calcMax(i, j, 1, board[i][j]);
            visited[i][j] = 0;
        }
    }
    return maxSum;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cout << getMaxSum() << endl;
}
