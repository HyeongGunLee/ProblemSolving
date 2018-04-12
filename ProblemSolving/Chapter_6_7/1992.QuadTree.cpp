#include <iostream>
#include <vector>
using namespace std;

int n;
int input[64][64];

void printQuadTree(int x, int y, int n) {
    int cur = input[x][y];
    bool flag = true;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (cur != input[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) {
        cout << cur;
    } else {
        int half = n/2;
        cout << "(";
        printQuadTree(x, y, half);
        printQuadTree(x, y+half, half);
        printQuadTree(x+half, y, half);
        printQuadTree(x+half, y+half, half);
        cout << ")";
    }

}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &input[i][j]);
        }
    }

    printQuadTree(0, 0, n);
}