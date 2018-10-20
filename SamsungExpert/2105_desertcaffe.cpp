#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
int map[20][20];
int visited[20][20];
int start_row, start_col;
int max_desert = -1;
int direction[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

bool isInside(int row, int col) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        return true;
    }
    return false;
}

bool isUniqueDesert(vector<int>& desert_list, int value) {
    int list_size = desert_list.size();
    for (int i = 0; i < list_size; i++) {
        if (desert_list[i] == value) {
            return false;
        }
    }
    return true;
}

void findDesert(vector<int>& desert_list, int row, int col, int dir) {

    for (int i = dir; i < 4; i++) {
        if (i != ((dir + 2) % 4)) {
            int nr = row + direction[i][0];
            int nc = col + direction[i][1];
            if (nr == start_row && nc == start_col) {
                int list_size = desert_list.size();
                max_desert = max(max_desert, list_size);
                return;
            }

            if (isInside(nr, nc) && !visited[nr][nc] && isUniqueDesert(desert_list, map[nr][nc])) {
                visited[nr][nc] = 1;
                desert_list.push_back(map[nr][nc]);
                findDesert(desert_list, nr, nc, i);
                visited[nr][nc] = 0;
                desert_list.pop_back();
            }
        }
    }
}

void findMaxDesert() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int> desert_list;
            start_row = i, start_col = j;
            visited[i][j] = 1;
            desert_list.push_back(map[i][j]);
            findDesert(desert_list, i, j, 0);
            desert_list.pop_back();
            visited[i][j] = 0;
        }
    }
}


int main(void) {
    cin >> T;
    int cur = 1;
    while (T > 0) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        findMaxDesert();
        cout << "#" << cur << " " << max_desert << endl;
        cur++;
        T--;
        max_desert = -1;
    }

}
