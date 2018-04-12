#include <iostream>
using namespace std;

int memo[30][30] = {-1,};
int n, r;

int bino(int n, int r) {
    if (n == 0 || r == n)
        return 1;
    if (memo[n][r] != -1)
        return memo[n][r];
    else
        return memo[n][r] = bino(n-1, r) + bino(n-1, r-1);
}

int main(void)
{
    cin >> n >> r;
    cout << bino(n, r) << endl;
    return 0;
}