#include <iostream>
using namespace std;


int ans = 0;
int coins[101];
int N, K;
int dp[100001] = {0, };

int calcCoin() {
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[K];
}

int main(void) {
    cin >> N  >> K;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    cout << calcCoin();

}
