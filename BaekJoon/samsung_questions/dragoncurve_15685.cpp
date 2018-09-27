#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int map[101][101] = {0, };
int lastX, lastY;
vector<int> curvePath;

void setCurve(int x, int y, int d) {
    int nx, ny;
    if (d == 0) {
        nx = x + 1;
        ny = y;
    } else if (d == 1) {
        nx = x;
        ny = y - 1;
    } else if (d == 2) {
        nx = x - 1;
        ny = y;
    } else if (d == 3) {
        nx = x;
        ny = y + 1;
    } else {
        return;
    }
    map[ny][nx] = 1;
    lastX = nx;
    lastY = ny;
}

/*
 * direction
 * 0 -> x + 1
 * 1 -> y - 1
 * 2 -> x - 1
 * 3 -> y + 1
 */
void dragonCurve(int x, int y, int d, int g) {
    vector<int> reversePath;
    map[y][x] = 1;
    setCurve(x, y, d);
    curvePath.push_back(d);

    for (int i = 1; i <= g; i++) {
        reversePath = curvePath;
        reverse(reversePath.begin(), reversePath.end());
        vector<int>::iterator it;
        for(it = reversePath.begin(); it != reversePath.end(); ++it) {
            *it += 1;
            *it = *it%4;
            curvePath.push_back(*it);
            setCurve(lastX, lastY, *it);
        }
    }

}

void initCurvePath() {
    while (!curvePath.empty()) {
        curvePath.pop_back();
    }
}

bool isSquare(int row, int col) {
    if (map[row][col+1] ==1 && map[row+1][col] == 1 && map[row+1][col+1] ==1) {
        return true;
    }
    return false;
}

int countSquare() {
    int squareCnt = 0;
    for (int row = 0; row < 100; row++) {
        for (int col = 0; col < 100; col++) {
            if (map[row][col] == 1 && isSquare(row, col)) {
                squareCnt++;
            }
        }
    }
    return squareCnt;
}


int main(void) {
    cin >> N;
    int x, y, d, g;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        initCurvePath();
        dragonCurve(x, y, d, g);
    }

    cout << countSquare() << endl;

    return 0;
}
