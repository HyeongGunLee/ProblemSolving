#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[100][100] = {0, };
int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        return true;
    }
    return false;
}

void normalDFS(vector<vector<char> >& section, int x, int y, char color) {
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (isInside(nx, ny) && (section[nx][ny] == color) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            normalDFS(section, nx, ny, color);
        }
    }
}

int normalSection(vector<vector<char> >& section) {
    int normalCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] != 1) {
                normalCount += 1;
                visited[i][j] = 1;
                normalDFS(section, i, j, section[i][j]);
            }
        }
    }
    return normalCount;
}

int colorBlindSection(vector<vector<char> >& section) {
    int colorBlindCnt = 0;
    // change G -> R
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (section[i][j] == 'G') {
                section[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                colorBlindCnt += 1;
                visited[i][j] = 1;
                normalDFS(section, i, j, section[i][j]);
            }
        }
    }
    return colorBlindCnt;
}


int main(void) {
    cin >> N;
    vector<vector<char> > section(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> section[i][j];
        }
    }

    cout << normalSection(section) << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
    cout << colorBlindSection(section) << endl;
    return 0;
}
