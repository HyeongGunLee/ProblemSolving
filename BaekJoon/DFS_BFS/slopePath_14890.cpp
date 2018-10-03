#include <iostream>
using namespace std;

int N, L;
int space[100][100];
int num_of_path = 0;
int placed[100];

bool canSetRow(int row, int col) {
    if (space[row][col] < space[row][col+1]) {  // 작은 경우
        if ((col-L+1) < 0) {
            return false;
        } else {
            for (int i = 0; i < L; i++) {
                if (space[row][col] != space[row][col-i] || placed[col-i]) {
                    return false;
                }
            }

            for (int i = 0; i < L; i++) {
                placed[col-i] = 1;
            }

        }
    } else { // 큰 경우
        if (col+L >= N) {
            return false;
        } else {
            for (int i = 0; i < L; i++) {
                if (space[row][col+1] != space[row][col+1+i] || placed[col+1+i]) {
                    return false;
                }
            }

            for (int i = 0; i < L; i++) {
                placed[col+i+1] = 1;
            }
        }
    }
    return true;
}

bool canSetCol(int row, int col) {
    if (space[row][col] < space[row+1][col]) {
        if ((row-L+1) < 0) {
            return false;
        } else {
            for (int i = 0; i < L; i++) {
                if (space[row][col] != space[row-i][col] || placed[row-i]) {
                    return false;
                }
            }

            for (int i = 0; i < L; i++) {
                placed[row-i] = 1;
            }
        }
    } else {
        if (row+L >= N) {
            return false;
        } else {
            for (int i = 0; i < L; i++) {
                if (space[row+1][col] != space[row+1+i][col] || placed[row+1+i]) {
                    return false;
                }
            }

            for (int i = 0; i < L; i++) {
                placed[row+i+1] = 1;
            }
        }
    }
    return true;
}


bool haveRowPath(int row) {
    for (int i = 0; i < N-1; i++) {
        if (space[row][i] == space[row][i+1]) {
            continue;
        } else if (abs(space[row][i]-space[row][i+1]) == 1) {
            if (!canSetRow(row, i)) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

bool haveColPath(int col) {
    for (int i = 0; i < N-1; i++) {
        if (space[i][col] == space[i+1][col]) {
            continue;
        } else if (abs(space[i][col]-space[i+1][col]) == 1) {
            if (!canSetCol(i, col)) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (haveRowPath(i)) {
            num_of_path++;
        }
        for (int i = 0; i < N; i++) {
            placed[i] = 0;
        }
        if (haveColPath(i)) {
            num_of_path++;
        }
        for (int i = 0; i < N; i++) {
            placed[i] = 0;
        }
    }
    cout << num_of_path << endl;
    return 0;
}
