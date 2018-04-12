#include <iostream>
using namespace std;


int getRegionSize(int matrix[100][100], int row, int col) {
    if (row < 0 || col < 0 || row > 100 || col > 100) {
        return 0;
    }

    if (matrix[row][col] == 0) {
        return 0;
    }
    matrix[row][col] = 0;

    int size = 1;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i != row || j != col) {
                size += getRegionSize(matrix, i, j);
            }
        }
    }
    return size;
}

int getBiggestRegion(int matrix[100][100], int width, int height) {
    int maxRegion = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (matrix[row][col] == 1) {
                int size = getRegionSize(matrix, row, col);
                maxRegion = max(maxRegion, size);
            }
        }
    }
    return maxRegion;
}

int main(void) {

}