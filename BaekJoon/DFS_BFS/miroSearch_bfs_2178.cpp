#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
typedef pair<int, int> position;

/*
 * start 0, 0
 * end N-1, M-1
 * BFS -> break if it gets to the end point
 */

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    return false;
}


// search miro with BFS
void searchMiro(vector<vector<int> >& miro, vector<vector<int> >& miroStep) {
    queue<position> q;
    q.push(make_pair(0, 0));
    miroStep[0][0] = 1;
    while(!q.empty()) {
        position cur = q.front();
        q.pop();
        if (cur.first == N-1 && cur.second == M-1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + direction[i][0];
            int ny = cur.second + direction[i][1];
            if (isInside(nx, ny) && miro[nx][ny] && miroStep[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                miroStep[nx][ny] = miroStep[cur.first][cur.second] + 1;
            }

        }

    }
}

int main(void) {
    cin >> N >> M;
    vector<vector<int> > miro(N, vector<int>(M));
    vector<vector<int> > miroStep(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }
    searchMiro(miro, miroStep);
    cout << miroStep[N-1][M-1] << endl;
    return 0;
}
