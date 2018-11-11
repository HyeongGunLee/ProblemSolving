#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char> >& grid);
    void dfs(vector<vector<char> >& grid, int x, int y);
    bool isInside(int x, int y);
private:
    int visited[1000][1000];
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rowLen;
    int colLen;
};

int Solution::numIslands(vector<vector<char> > &grid) {
    int numOfIslands = 0;
    rowLen = grid.size();
    if(!rowLen)
        return 0;
    colLen = int(grid[0].size());
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < colLen; j++) {
            if (visited[i][j] == 0 && grid[i][j] == '1') {
                dfs(grid, i, j);
                numOfIslands++;
            }
        }
    }
    return numOfIslands;
}

void Solution::dfs(vector<vector<char> > &grid, int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (isInside(nx, ny) && visited[nx][ny] == 0 && grid[nx][ny] == '1') {
            dfs(grid, nx, ny);
        }
    }
}

bool Solution::isInside(int x, int y) {
    if (x >= 0 && x < rowLen && y >= 0 && y < colLen) {
        return true;
    }
    return false;
}

int main(void) {
    vector<vector<char> > grid(4, vector<char>(5, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    Solution test = Solution();
    cout << test.numIslands(grid) << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
