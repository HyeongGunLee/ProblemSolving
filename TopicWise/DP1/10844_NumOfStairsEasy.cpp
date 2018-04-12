#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<long long>> memo;

long long findStair(int index, int num)
{
    if (index < 0 || num < 0 || num > 9 ) return 0;
    if (index >= N) return 1;

    long long &ret = memo[index][num];
    if (ret != 0) return ret;

    return ret += (findStair(index + 1, num - 1) + findStair(index + 1, num + 1)) % 1000000000;

}

int main(void)
{
    int answer = 0;
    scanf("%d", &N);
    N--;
    memo = vector<vector<long long>>(N, vector<long long>(10, 0));
    for (int i = 1; i <= 9; ++i) {
        answer += findStair(0, i);
    }
    cout << answer%1000000000 << endl;
}