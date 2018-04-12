#include <iostream>
#include <climits>
using namespace std;

int N;
long long arr[1000001];


long long solve(long long arr[]) {
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    for (int i = 0; i < N; i++) {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;



    }
    return max_so_far;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << solve(arr) << endl;
}