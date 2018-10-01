#include <iostream>
#include <cmath>
using namespace std;

int k;
int wheel[4][8];
int visited[4];

void moveWheel(int w_num, int direction) {
    if (direction == 1) {
        int temp = wheel[w_num-1][7];
        for (int i = 0; i < 7; i++) {
            wheel[w_num-1][7-i] = wheel[w_num-1][6-i];
        }
        wheel[w_num-1][0] = temp;
    } else if (direction == -1) {
        int temp = wheel[w_num-1][0];
        for (int i = 0; i < 7; i++) {
            wheel[w_num-1][i] = wheel[w_num-1][i+1];
        }
        wheel[w_num-1][7] = temp;
    }
}

void rotateWheel(int w_num, int direction) {
    visited[w_num-1] = 1;
    if (w_num == 1) {
        if (wheel[w_num-1][2] != wheel[w_num][6] && !visited[w_num]) {
            visited[w_num] = 1;
            rotateWheel(w_num+1, -1*direction);
        }
    } else if (w_num == 2) {
        if (wheel[w_num-1][2] != wheel[w_num][6] && !visited[w_num]) {
            visited[w_num] = 1;
            rotateWheel(w_num+1, -1*direction);
        }
        if (wheel[w_num-1][6] != wheel[w_num-2][2] && !visited[w_num-2]) {
            visited[w_num-2] = 1;
            rotateWheel(w_num-1, -1*direction);
        }
    } else if (w_num == 3) {
        if (wheel[w_num-1][2] != wheel[w_num][6] && !visited[w_num]) {
            visited[w_num] = 1;
            rotateWheel(w_num+1, -1*direction);
        }
        if (wheel[w_num-1][6] != wheel[w_num-2][2] && !visited[w_num-2]) {
            visited[w_num-2] = 1;
            rotateWheel(w_num-1, -1*direction);
        }
    } else if (w_num == 4) {
        if (wheel[w_num-1][6] != wheel[w_num-2][2] && !visited[w_num-2]) {
            visited[w_num-2] = 1;
            rotateWheel(w_num-1, -1*direction);
        }
    }
    moveWheel(w_num, direction);
}

int calcScore() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == 1) {
            sum += pow(2, i);
        }
    }
    return sum;
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &wheel[i][j]);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int w_num, direction;
        cin >> w_num >> direction;
        for (int i = 0; i < 4; i++) {
            visited[i] = 0;
        }
        rotateWheel(w_num, direction);
    }

    cout << calcScore() << endl;

}
