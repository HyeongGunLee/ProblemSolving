#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];
int visited[1001][1001] = {0, };
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int row, col;

typedef struct {
    int row;
    int col;
    int day;
} coordi;

bool isInside(int x, int y) {
    if (x < row && x >= 0 && y < col && y >= 0) {
        return true;
    }
    return false;
}

int bfs() {
    queue<coordi> q;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (box[i][j] == 1) {
                coordi temp;
                temp.row = i;
                temp.col = j;
                temp.day = 1;
                q.push(temp);
            }
        }
    }

    if (q.empty()) {
        return -1;
    }

    while (!q.empty()) {
        coordi temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = temp.row + direction[i][0];
            int nc = temp.col + direction[i][1];
            if (isInside(nr, nc)) {
                if (box[nr][nc] == 0  && visited[nr][nc] != 1) {
                    coordi new_cd;
                    new_cd.row = nr;
                    new_cd.col = nc;
                    new_cd.day = temp.day + 1;
                    q.push(new_cd);
                    box[nr][nc] = temp.day + 1;
                    visited[nr][nc] = 1;
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (box[i][j] == 0) {
                return -1;
            }
        }
    }

    int max_day = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (box[i][j] > max_day) {
                max_day = box[i][j];
            }
        }
    }

    return max_day-1;
}


// 다 익는 날짜 return, 아니면 -1
int main(void) {
    cin >> col >> row;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> box[i][j];
        }
    }
    cout << bfs();

}
