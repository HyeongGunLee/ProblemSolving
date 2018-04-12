#include <iostream>
#include <vector>
using namespace std;

int N;
vector <vector<long long>> memo;

//Top Down Approach
/*
long long findStair(int index, int num)
{
    if (index < 0 || num > 9 || num < 0) return 0;
    if (index >= N) return 1;

    long long& ret = memo[index][num];
    if (ret != 0) return ret;

    for (int i = 0; i < 10 - num; ++i) {
        ret += findStair(index + 1, num+i);
    }
    ret %= 10007;
    return ret;
}

int main(void)
{
    int ans = 0;
    scanf("%d", &N);
    N--;
    memo = vector<vector<long long>>(N, vector<long long>(10, 0));
    for (int i = 0; i < 10; ++i) {
        ans += findStair(0, i);
    }
    cout << ans % 10007<< endl;
    return 0;
}

*/

//Bottom up approach

void findStair()
{
    for (int i = 0; i < 10; ++i)
        memo[0][i] = 1;

    for (int i = 1; i <= N; i++) {
        memo[i][9] = 1;
        for (int j = 8; j >= 0; j--) {
            memo[i][j] = (memo[i][j+1] + memo[i-1][j])%10007;
        }
    }
}

int main(void)
{
    scanf("%d", &N);
    N;
    memo = vector<vector<long long>>(N, vector<long long>(10, 1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    findStair();
    cout << memo[N][0];
    return 0;
}