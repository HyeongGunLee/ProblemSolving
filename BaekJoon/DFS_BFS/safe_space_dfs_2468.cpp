#include <iostream>
using namespace std;

int N;
int area[100][100];
bool visited[100][100];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y, int h) {
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];

        if (ny<0 || ny >= N || nx<0 || ny>= N)
            continue;

        if (area[nx][ny] <= h || visited[nx][ny])
            continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, h);
    }
}

int main(void) {
    cin >> N;
    int max_height = 0;
    int min_height = 9876543;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
            min_height = min(min_height, area[i][j]);
            max_height = max(max_height, area[i][j]);
        }
    }

    int maxSafe = 1;
    for (int h = min_height; h <= max_height; h++) {
        memset(visited, 0, sizeof(visited));

        int safeCnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (area[i][j] > h && !visited[i][j]) {
                    visited[i][j] = 1;
                    safeCnt++;
                    dfs(i, j, h);
                }
            }
        }
        maxSafe = max(maxSafe, safeCnt);
    }
    cout << maxSafe << endl;
    return 0;
}
