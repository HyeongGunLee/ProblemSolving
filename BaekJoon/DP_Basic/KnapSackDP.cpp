#include <iostream>
using namespace std;

const int MAXN = 105;
int N, W[MAXN], V[MAXN], C;
int D[MAXN][MAXN];

int solve() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            D[i][j] = -98766342;
        }
    }


    /*
     *  Arr D is being used for storing max Value on index i (to pick), and accumulated capacity j
     *  Time Complexity O(NC)
     */

    D[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= C; i++) {
            D[i+1][j] = max(D[i+1][j], D[i][j]); // did not choose current one
            if (j + W[i] <= C) {
                D[i+1][j + W[i]] = max(D[i+1][j+W[i]], D[i][j] + V[i]);
            }
        }
    }
    int ans = -98765432;
    for (int i = 0; i <= C; i++) {
        ans = max(ans, D[N][i]);
    }
    return ans;
}



// #2
int pack(int capacity, int item) {
    if (item == n) return 0;

    int& ret = cache[capacity][item];
    if (ret != -1) {
        return ret;
    }

    ret = pack(capacity, item+1);
    if (volumn[item] <= capacity) {
        ret = max(ret, pack(capacity-volumn[item]) + need[item]);
    }
    return ret;
}

