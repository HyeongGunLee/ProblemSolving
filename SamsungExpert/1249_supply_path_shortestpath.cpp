#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int T, N;
int board[101][101];
int result[101][101];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //N, E, S, W

struct cell {
    int x, y;
    int distance;
    cell (int x, int y, int distance) :
        x(x), y(y), distance(distance) {}
};

bool operator<(const cell& a, const cell& b) {
    if (a.distance == b.distance) {
        if (a.x != b.x) {
            return (a.x < b.x);
        } else {
            return (a.y < b.y);
        }
    }
    return (a.distance < b.distance);
}


void initBoard() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            board[i][j] = 0;
            result[i][j] = 0;
        }
    }
}

bool isInside(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return false;
    }
    return true;
}

int shortestPath() {
    int dis[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dis[i][j] = 987654321;
        }
    }

    set<cell> st;
    st.insert(cell(0, 0, 0));
    dis[0][0] = board[0][0];

    while (!st.empty()) {
        cell k = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++) {
            int nx = k.x + direction[i][0];
            int ny = k.y + direction[i][1];

            if (!isInside(nx, ny)) {
                continue;
            }

            if (dis[nx][ny] > dis[k.x][k.y] + board[nx][ny]) {
                if (dis[nx][ny] != 987654321) {
                    st.erase(st.find(cell(nx, ny, dis[nx][ny])));
                }
                dis[nx][ny] = dis[k.x][k.y] + board[nx][ny];
                st.insert(cell(nx, ny, dis[nx][ny]));
            }
        }
    }
    return dis[N-1][N-1];
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
        // find a shortest path to the end here
        cout << "#" << x+1 << " " << shortestPath() << endl;
    }
}
