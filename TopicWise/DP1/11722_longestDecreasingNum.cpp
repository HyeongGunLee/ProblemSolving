#include <iostream>
using namespace std;

int N;
int num[1001];
int arr[1001];


void solve()
{
    for (int i = 0; i <= N; ++i) {
        arr[i] = 1;
    }

    num[0] = 0;
    arr[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            if (num[j] < num[i]) {
                arr[j] = max(arr[j], arr[i]+1);
            }
        }
    }
}


int main(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", &num[i]);
    }
    solve();

    /*
    for (int i = 0; i <= N; ++i) {
        cout << arr[i] << " ";
    }
    */
    int ans = 0;


    for (int i = 1; i <= N; ++i) {
        ans = max(ans, arr[i]);
    }

    cout << ans << endl;

    return 0;
}