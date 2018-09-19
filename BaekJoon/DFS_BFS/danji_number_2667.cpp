#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N = 100;
int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int num_of_house = 0;
vector<int> danji_list;

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        return true;
    }
    return false;
}


void dfs(vector<vector<int> >& danjiMap, vector<vector<bool> >& visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (isInside(nx, ny)) {
            if (danjiMap[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                danjiMap[nx][ny] = 2;
                num_of_house += 1;
                dfs(danjiMap, visited, nx, ny);
            }
        }
    }
}

int countDanji(vector<vector<int> >& danjiMap, vector<vector<bool> >& visited) {
    int danji_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (danjiMap[i][j] == 1 && visited[i][j] != 1) {
                danji_count += 1;
                num_of_house = 1;
                visited[i][j] = 1;
                danjiMap[i][j] = 2;
                dfs(danjiMap, visited, i, j);
                danji_list.push_back(num_of_house);
            }
        }
    }
    return danji_count;
}


int main(void) {
    cin >> N;
    vector<vector<int> > danjiMap(N, vector<int>(N));
    vector<vector<bool> > visited(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &danjiMap[i][j]) ;
        }
    }

    cout << countDanji(danjiMap, visited) << endl;


    sort(danji_list.begin(), danji_list.end());

    vector<int>::iterator it;
    for(it = danji_list.begin(); it != danji_list.end(); ++it) {
        cout << *it << endl;
    }

}
