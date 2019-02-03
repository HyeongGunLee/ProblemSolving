#include <iostream>
using namespace std;

int N;
int A[1001];
int S[1001];

int solve() {

    for (int i = 0; i <= N; i++) {
        S[i] = -98765432;
    }

    S[0] = 0;
    A[0] = 0;


    for (int i = 0; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (A[j] > A[i]) {
                S[j] = max(S[j], S[i] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, S[i]);
    }
    return ans;

}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    cout << solve() << endl;
}
