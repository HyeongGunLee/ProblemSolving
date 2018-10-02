#include <iostream>
using namespace std;

int N, M;
int space[500][500];
int visited[500][500];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int max_sum = -1;
bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    return false;
}

void dfs(int x, int y, int sum, int cnt) {
    if (cnt == 4) {
        max_sum = max(max_sum, sum);
        return;
    } else if (cnt > 4) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        int e_x = x + direction[(i+1)%4][0];
        int e_y = y + direction[(i+1)%4][1];

        if (isInside(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            dfs(nx, ny, sum + space[nx][ny], cnt+1);
            visited[nx][ny] = 0;

            if (isInside(e_x, e_y) && !visited[e_x][e_y]) {
                visited[e_x][e_y] = 1;
                visited[nx][ny] = 1;
                dfs(nx, ny, sum + space[e_x][e_y] + space[nx][ny], cnt+2);
                visited[nx][ny] = 0;
                visited[e_x][e_y] = 0;
            }
        }
    }

}


void findMax() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            dfs(i, j, space[i][j], 1);
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
        }
    }
    findMax();
    cout << max_sum << endl;
}
