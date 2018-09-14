#include <iostream>
#include <queue>
using namespace std;

int N;
int area[101][101];
bool submerged[101][101];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef struct {
    int x;
    int y;
} pos;

bool isInside(int x, int y) {
  if ((x >= 0 && x < N) && (y >= 0 && y < N)) {
    return true;
  }
  return false;
}

int calcSafeSpace() {
  queue<pos> q;
  int safeCount = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!submerged[i][j]) {
        safeCount += 1;
        pos temp;
        temp.x = i;
        temp.y = j;
        q.push(temp);
        submerged[i][j] = 1;
        while(!q.empty()) {
          pos ex = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nx = ex.x + direction[k][0];
            int ny = ex.y + direction[k][1];

            if (isInside(nx, ny)) {
              if (!submerged[nx][ny]) {
                pos newPos;
                newPos.x = nx;
                newPos.y = ny;
                q.push(newPos);
                submerged[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
  }
  return safeCount;
}


int maxSafeSpace(int minVal, int maxVal) {
  int maxSafeSpace = 1;
  // min height ~ max height
  for (int h = 0; h < maxVal; h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (area[i][j] <= h) {
          submerged[i][j] = 1;
        }
      }
    }

    int safeSpace = calcSafeSpace();
    if (safeSpace >= maxSafeSpace) {
      maxSafeSpace = safeSpace;
    }

    // initialize submerged & visited
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        submerged[x][y] = 0;
      }
    }
  }
  return maxSafeSpace;
}

int main(void) {
  int minVal = 98764321;
  int maxVal = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> area[i][j];
      minVal = min(area[i][j], minVal);
      maxVal = max(area[i][j], maxVal);
    }
  }

  cout << maxSafeSpace(minVal, maxVal) << endl;
}
