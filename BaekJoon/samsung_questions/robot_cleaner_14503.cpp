#include <iostream>
using namespace std;

int N, M;
int area[50][50];
int r, c, d;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // N E S W
int total = 0;

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    return false;
}

void findSpaceToClean(int row, int col, int d) {
    int nr, nc, nd;
    for (int i = 0; i < 4; i++) {
        nd = (d+3)%4;
        nr = row + direction[nd][0];
        nc = col + direction[nd][1];

        if (area[nr][nc] == 0) {
            area[nr][nc] = 2;
            total++;
            findSpaceToClean(nr, nc, nd);
            return;
        } else {
            d = nd;
        }

    }

    int back_dir = (d+2)%4;
    nr = row + direction[back_dir][0];
    nc = col + direction[back_dir][1];
    if (area[nr][nc] == 1) {
        return;
    } else {
        findSpaceToClean(nr, nc, d);
    }
}

int main(void) {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
        }
    }
    area[r][c] = 2;
    total++;
    findSpaceToClean(r, c, d);
    cout << total << endl;
    return 0;
}
