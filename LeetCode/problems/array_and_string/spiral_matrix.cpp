#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    bool visited[1000][1000] = {0, };
    int max_row;
    int max_col;
public:

    bool canMoveRight(int x, int y);
    bool canMoveDown(int x, int y);
    bool canMoveLeft(int x, int y);
    bool canMoveUp(int x, int y);


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        this->max_row = matrix.size();
        this->max_col = matrix[0].size();
        int _row = 0;
        int _col = 0;
        this->visited[0][0] = 1;
        result.push_back(matrix[0][0]);
        while (true) {
            if (canMoveRight(_row, _col)) {
                // move right;
                _col += 1;
                visited[_row][_col] = 1;
                result.push_back(matrix[_row][_col]);
            } else if (canMoveDown(_row, _col)) {
                // move down;
                _row += 1;
                visited[_row][_col] = 1;
                result.push_back(matrix[_row][_col]);
            } else if (canMoveLeft(_row, _col)) {
                // move left;
                _col -= 1;
                visited[_row][_col] = 1;
                result.push_back(matrix[_row][_col]);
            } else if (canMoveUp(_row, _col)) {
                // move up
                _row -= 1;
                visited[_row][_col] = 1;
                result.push_back(matrix[_row][_col]);
            } else {
                break;
            }
        }
        return result;
    }
};

bool Solution::canMoveRight(int x, int y) {
    if (x < this->max_row && x >= 0 && y >= 0 && (y+1) < max_col && this->visited[x][y+1] != 1) {
        return true;
    }
    return false;
}

bool Solution::canMoveDown(int x, int y) {
    if ((x+1) < this->max_row && x >= 0 && y >= 0 && y < max_col && this->visited[x+1][y] != 1) {
        return true;
    }
    return false;
}

bool Solution::canMoveLeft(int x, int y) {
    if (x < this->max_row && x >= 0 && (y-1) >= 0 && y < max_col && this->visited[x][y-1] != 1) {
        return true;
    }
    return false;
}

bool Solution::canMoveUp(int x, int y) {
    if ((x-1) < this->max_row && (x-1) >= 0 && y >= 0 && y < max_col && this->visited[x-1][y] != 1) {
        return true;
    }
    return false;
}


int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> v1 (4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v1[i][j];
        }
    }

    vector<int> result = test->spiralOrder(v1);

    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
}
