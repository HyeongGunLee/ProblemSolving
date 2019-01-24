#:wqinclude <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;


int N;
int main(void) {
    cin >> N;
    vector<long long> arr;
    long long temp;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    int ans_cnt = 1;
    long long ans = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i-1]) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (ans_cnt < cnt) {
            ans_cnt = cnt;
            ans = arr[i];
        }
    }
    cout << ans << endl;

}
