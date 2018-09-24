#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector<int> stepList;
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int curMin = 987654321;
/*
 *  start point = 0, 0
 *  end point = N-1, M-1
 *  add to step list if it gets to the end point
 */

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    return false;
}


// search miro with DFS
void searchMiro(int x, int y, vector<vector<int> >& miro, vector<vector<bool> >& visited, int step) {
    if (x == N-1 && y == M-1) {
        stepList.push_back(step);
        curMin = min(curMin, step);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (isInside(nx, ny)) {
            if (miro[nx][ny] && !visited[nx][ny] && step < curMin) {
                visited[nx][ny] = 1;
                searchMiro(nx, ny, miro, visited, step+1);
                visited[nx][ny] = 0;
            }
        }
    }
}

int getMinimumStep() {
    int minStep = 987654321;
    int step_len = stepList.size();
    for (int i = 0; i < step_len; i++) {
        minStep = min(minStep, stepList[i]);
    }
    return minStep;
}

int main(void) {
    cin >> N >> M;
    vector<vector<int> > miro(N, vector<int>(M));
    vector<vector<bool> > visited(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }

    visited[0][0] = 1;
    searchMiro(0, 0, miro, visited, 1);
//    cout << getMinimumStep() << endl;
    cout << curMin << endl;
    return 0;
}
