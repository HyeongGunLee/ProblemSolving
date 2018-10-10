#include <iostream>
#include <queue>
using namespace std;

int T, N, M, R, C, L;
int map[50][50];
int visited[50][50];
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int opened[4][4] = { {1, 2, 4, 7}, {1, 3, 4, 5}, {1, 2, 5, 6}, {1, 3, 6, 7} };

typedef struct {
    int x;
    int y;
} position;

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    return false;
}

bool isMatch(int dir, int tunnel) {
    if (dir == 0) {
        for (int i = 0; i < 4; i++) {
            if (tunnel == opened[2][i]) {
                return true;
            }
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < 4; i++) {
            if (tunnel == opened[3][i]) {
                return true;
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < 4; i++) {
            if (tunnel == opened[0][i]) {
                return true;
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < 4; i++) {
            if (tunnel == opened[1][i]) {
                return true;
            }
        }
    }
    return false;
}

int countVisited() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 1) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

void runThief(int row, int col, int time) {
    int depth = 1;
    queue<position> q;
    position temp;
    temp.x = row;
    temp.y = col;
    q.push(temp);
    visited[row][col] = 1;
    position end;
    end.x = 99;
    end.y = 99;
    q.push(end);
    while (!q.empty() && depth < time) {
        position cur_pos = q.front();
        q.pop();
        if (cur_pos.x == 99) {
            depth += 1;
            q.push(end);
            if (q.front().x == 99) {
                break;
            }
            else {
                continue;
            }
        }

        int map_pos = map[cur_pos.x][cur_pos.y];
        if (map_pos == 1) {
            for (int i = 0; i < 4; i++) {
                int nr = cur_pos.x + direction[i][0];
                int nc = cur_pos.y + direction[i][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(i, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 2) {
            for (int i = 0; i < 2; i++) {
                int dir = 2 * i;
                int nr = cur_pos.x + direction[dir][0];
                int nc = cur_pos.y + direction[dir][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(dir, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 3) {
            for (int i = 0; i < 2; i++) {
                int dir = 1 + 2 * i;
                int nr = cur_pos.x + direction[dir][0];
                int nc = cur_pos.y + direction[dir][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(dir, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 4) {
            for (int i = 0; i < 2; i++) {
                int nr = cur_pos.x + direction[i][0];
                int nc = cur_pos.y + direction[i][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(i, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 5) {
            for (int i = 0; i < 2; i++) {
                int dir = i + 1;
                int nr = cur_pos.x + direction[dir][0];
                int nc = cur_pos.y + direction[dir][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(dir, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 6) {
            for (int i = 0; i < 2; i++) {
                int dir = i + 2;
                int nr = cur_pos.x + direction[dir][0];
                int nc = cur_pos.y + direction[dir][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(dir, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else if (map_pos == 7) {
            for (int i = 0; i < 2; i++) {
                int dir = (i + 3) % 4;
                int nr = cur_pos.x + direction[dir][0];
                int nc = cur_pos.y + direction[dir][1];
                if (isInside(nr, nc) && !visited[nr][nc] && isMatch(dir, map[nr][nc])) {
                    visited[nr][nc] = 1;
                    position new_pos;
                    new_pos.x = nr;
                    new_pos.y = nc;
                    q.push(new_pos);
                }
            }
        }
        else {
            continue;
        }
    }
}

int main(void) {
    cin >> T;
    int cur = 1;
    while (T > 0) {
        cin >> N >> M >> R >> C >> L;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        runThief(R, C, L);
        cout << "#" << cur << " " << countVisited() << endl;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        cur += 1;
        T--;
    }


}

