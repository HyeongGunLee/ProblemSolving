#include <iostream>
using namespace std;


int n;
int ans[11];

int numOfSum(int k) {
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    if (k < 4) {
        return ans[k];
    }

    for (int i = 4; i <= k; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[k];
}

int main(void) {
    cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << numOfSum(k) << endl;
    }
}
