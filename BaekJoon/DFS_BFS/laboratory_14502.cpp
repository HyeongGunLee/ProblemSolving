#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//typedef struct {
//    int x;
//    int y;
//} pos;

int N, M;
typedef pair<int, int> pos;
queue<pos> q;
vector<vector<int> > lab(8, vector<int>(8));
vector<vector<int> > visited(8, vector<int>(8));
int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool isEmpty(int index) {
    if (index == 0) {
        return lab[0][0] == 0;
    }
    int row = index/M;
    int col = index%M;
    return lab[row][col] == 0;
}

void setWall(int index) {
    if (index == 0) {
        lab[0][0] = 1;
    } else {
        int row = index/M;
        int col = index%M;
        lab[row][col] = 1;
    }
}

bool isInside(int x, int y) {
    if ((x >= 0 && x < N) && (y >= 0 && y < M)) {
        return true;
    }
    return false;
}

void spreadVirus() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        pos temp = q.front();
        q.pop();
//        visited[temp.first][temp.second] = 1;
        for (int i = 0; i < 4; i++) {
            int dx = temp.first + direction[i][0];
            int dy = temp.second + direction[i][1];

            if (isInside(dx, dy)) {
                if (lab[dx][dy] == 0 && visited[dx][dy] != 1) {
                    q.push(make_pair(dx, dy));
                    lab[dx][dy] = 3;
                    visited[dx][dy] = 1;
                }
            }
        }
    }
}

int searchSafeZone() {
    int space = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 0) {
                space += 1;
            }
        }
    }
    return space;
}

void initialize(int a, int b, int c) {
    // visited == all zero, lab
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 3) {
                lab[i][j] = 0;
            }
        }
    }

    int row = a/M;
    int col = a%M;
    lab[row][col] = 0;
    row = b/M;
    col = b%M;
    lab[row][col] = 0;
    row = c/M;
    col = c%M;
    lab[row][col] = 0;

    // initialize visited
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }


}


int findMaxSafeZone() {
    int maxZone = -99999;
    int labSize = N*M;

    for (int i = 0; i < labSize-2; i++) {
        for (int j = i+1; j < labSize-1; j++) {
            for (int k = j+1; k < labSize; k++) {
                if (isEmpty(i) && isEmpty(j) && isEmpty(k)) {
                    setWall(i);
                    setWall(j);
                    setWall(k);
                    spreadVirus();
                    int safeZone = searchSafeZone();

                    initialize(i, j, k);

                    if (maxZone <= safeZone) {
                        maxZone = safeZone;
                    }
                }
            }
        }
    }
    return maxZone;
}


int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
        }
    }

    cout << findMaxSafeZone() << endl;
}

