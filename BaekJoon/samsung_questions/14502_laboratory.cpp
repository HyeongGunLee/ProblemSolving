#include <iostream>
#include <queue>
using namespace std;


int N, M;
int board[8][8];
bool visited[8][8] = { 0,};
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int maxSafeRegion = -1;

struct iPair {
    int r, c;
    iPair(int r, int c) : r(r), c(c) {};
};

bool canSet(int x, int y, int z) {
    int x_r = x / M;
    int x_c = x % M;
    int y_r = y / M;
    int y_c = y % M;
    int z_r = z / M;
    int z_c = z % M;
    if (board[x_r][x_c] == 0 && board[y_r][y_c] == 0 && board[z_r][z_c] == 0) {
        return true;
    }
    return false;
}

void setWall(int x, int y, int z) {
    int x_r = x / M;
    int x_c = x % M;
    int y_r = y / M;
    int y_c = y % M;
    int z_r = z / M;
    int z_c = z % M;
    board[x_r][x_c] = 1;
    board[y_r][y_c] = 1;
    board[z_r][z_c] = 1;
}

bool isInside(int r, int c) {
    if (r >= 0 && r < N && c >= 0 && c < M) {
        return true;
    }
    return false;
}

void spread(int r, int c) {
    queue<iPair> q;
    q.push(iPair(r, c));

    while (!q.empty()) {
        iPair temp = q.front();
        q.pop();
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = temp.r + direction[i][0];
            int nc = temp.c + direction[i][1];
            if (!visited[nr][nc] && board[nr][nc] == 0 && isInside(nr, nc)) {
                visited[nr][nc] = 1;
                board[nr][nc] = 2;
                q.push(iPair(nr, nc));
            }
        }
    }
}

void spreadVirus() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2 && !visited[i][j]) {
                spread(i, j);
            }
        }
    }
}

int calcRegion() {
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                result += 1;
            }
        }
    }
    return result;
}

void initBoard(int tempBoard[8][8]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = tempBoard[i][j];
            visited[i][j] = false;
        }
    }
}

int getMaxRegion() {
    int boardLen = N * M;
    int tempBoard[8][8];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tempBoard[i][j] = board[i][j];
        }
    }

    for (int x = 0; x < boardLen - 2; x++) {
        for (int y = x+1; y < boardLen - 1; y++) {
            for (int z = y + 1; z < boardLen; z++) {
                initBoard(tempBoard);
                if (canSet(x, y, z)) {
                    setWall(x, y, z);
                    spreadVirus();
                    maxSafeRegion = max(maxSafeRegion, calcRegion());
                }
            }
        }
    }
    return maxSafeRegion;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cout << getMaxRegion() << endl;
}
