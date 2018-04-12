#include <iostream>
using namespace std;

int N;
int cache[1000001];


int solve(int n) {
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;

    for (int i = 4; i <= n; i++) {
        cache[i] = i;
        for (int x = 1; x <= i; x++) {
            int temp = x*x;
            if (temp > i)
                break;
            else
                cache[i] = min(cache[i], cache[i-temp] + 1);
        }
    }
    return cache[n];

}

int main(void) {
    cin >> N;
    cout << solve(N);
}