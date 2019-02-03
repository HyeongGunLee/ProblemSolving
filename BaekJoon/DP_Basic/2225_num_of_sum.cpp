#include <iostream>
using namespace std;

int N, K;
int cnt[201][201];
int x = 1000000000;
int numOfSum() {
    for (int i = 1; i <= K; i++) {
        cnt[1][i] = i;
    }

    for (int i = 1; i <= N; i++) {
        cnt[i][1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
            cnt[i][j] %= x;
        }
    }
    return cnt[N][K];
}

int main(void) {
    cin >> N >> K;
    cout << numOfSum() << endl;
}

