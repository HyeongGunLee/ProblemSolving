#include <iostream>
using namespace std;

int N;
int A[1002];
int max_left[1001];
int max_right[1002];
int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= 1000; i++) {
        max_left[i] = -1;
        max_right[i] = -1;
    }
    A[0] = 0;
    max_left[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (A[j] > A[i]) {
                max_left[j] = max(max_left[j], max_left[i]+1);
            }
        }
    }

    A[N+1] = 0;
    max_right[N+1] = 0;
    for (int i = N+1; i > 1; i--) {
        for (int j = i-1; j > 0; j--) {
            if (A[j] > A[i]) {
                max_right[j] = max(max_right[j], max_right[i]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, max_left[i]+max_right[i]-1);
    }
    cout << ans << endl;

}
