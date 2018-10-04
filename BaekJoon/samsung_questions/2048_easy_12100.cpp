#include <iostream>
#include <vector>
using namespace std;


int N;
int board[20][20];
int initBoard[20][20];
int max_num = -1;

void moveBoard(int direct) {
    if (direct == 0) { // North
        for (int col = 0; col < N; col++) {
            vector<int> val_list;
            for (int row = 0; row < N; row++) { // check val and add to val_list, set board[][] = 0
                if (board[row][col] != 0) {
                    val_list.push_back(board[row][col]);
                    board[row][col] = 0;
                }
            }

            int val_size = val_list.size();
            int k = 0;
            if (val_size == 0) {
                continue;
            } else if (val_size == 1) {
                board[k][col] = val_list[0];
            } else {
                for (int j = 0; j < val_size; j++) {
                    if ((j+1) < val_size && val_list[j] == val_list[j+1]) {
                        board[k][col] = val_list[j] * 2;
                        j++;
                        k++;
                    } else {
                        board[k][col] = val_list[j];
                        k++;
                    }
                }
            }
        }
    } else if (direct == 1) { // East
        for (int row = 0; row < N; row++) {
            vector<int> val_list;
            for (int col = N-1; col >= 0; col--) { // check val and add to val_list, set board[][] = 0
                if (board[row][col] != 0) {
                    val_list.push_back(board[row][col]);
                    board[row][col] = 0;
                }
            }

            int val_size = val_list.size();
            int k = N-1;
            if (val_size == 0) {
                continue;
            } else if (val_size == 1) {
                board[row][k] = val_list[0];
            } else {
                for (int j = 0; j < val_size; j++) {
                    if ((j+1) < val_size && val_list[j] == val_list[j+1]) {
                        board[row][k] = val_list[j] * 2;
                        j++;
                        k--;
                    } else {
                        board[row][k] = val_list[j];
                        k--;
                    }
                }
            }
        }
    } else if (direct == 2) { // South
        for (int col = 0; col < N; col++) {
            vector<int> val_list;
            for (int row = N-1; row >= 0; row--) { // check val and add to val_list, set board[][] = 0
                if (board[row][col] != 0) {
                    val_list.push_back(board[row][col]);
                    board[row][col] = 0;
                }
            }

            int val_size = val_list.size();
            int k = N-1;
            if (val_size == 0) {
                continue;
            } else if (val_size == 1) {
                board[k][col] = val_list[0];
            } else {
                for (int j = 0; j < val_size; j++) {
                    if ((j+1) < val_size && val_list[j] == val_list[j+1]) {
                        board[k][col] = val_list[j] * 2;
                        j++;
                        k--;
                    } else {
                        board[k][col] = val_list[j];
                        k--;
                    }
                }
            }
        }
    } else if (direct == 3) { // West
        for (int row = 0; row < N; row++) {
            vector<int> val_list;
            for (int col = 0; col < N; col++) { // check val and add to val_list, set board[][] = 0
                if (board[row][col] != 0) {
                    val_list.push_back(board[row][col]);
                    board[row][col] = 0;
                }
            }

            int val_size = val_list.size();
            int k = 0;
            if (val_size == 0) {
                continue;
            } else if (val_size == 1) {
                board[row][k] = val_list[0];
            } else {
                for (int j = 0; j < val_size; j++) {
                    if ((j+1) < val_size && val_list[j] == val_list[j+1]) {
                        board[row][k] = val_list[j] * 2;
                        j++;
                        k++;
                    } else {
                        board[row][k] = val_list[j];
                        k++;
                    }
                }
            }
        }
    } else {
        return;
    }
}

void updateMax() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            max_num = max(max_num, board[i][j]);
        }
    }
}

void findMax(vector<int>& direction_list, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < 5; i++) {
            moveBoard(direction_list[i]);
        }
        updateMax();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = initBoard[i][j];
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        direction_list.push_back(i);
        findMax(direction_list, cnt+1);
        direction_list.pop_back();
    }
}


int main(void) {
    cin >> N;
    vector<int> direction_list;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            initBoard[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        direction_list.push_back(i);
        findMax(direction_list, 1);
        direction_list.pop_back();
    }
    cout << max_num << endl;
}
