#include <iostream>
#include <stdio.h>
using namespace std;

long long int ans[1001];
int N;

int main(void)
{
    scanf("%d", &N);
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= N; ++i) {
        ans[i] = (ans[i-1] + ans[i-2])%10007;
    }

    printf("%lld", ans[N]);
    return 0;
}