#include <iostream>
#include <cstdio>
using namespace std;


int T;
int N;
int arr[101];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

long long sumOfGCD(int num) {
    long long sum = 0;
    for (int i = 0; i < num-1; i++) {
        for (int j = i+1; j < num; j++) {
            sum += gcd(arr[i], arr[j]);
        }
    }
    return sum;
}


int main(void) {
    scanf(" %d", &T);

    for (int i = 0; i < T; i++) {
        scanf(" %d", &N);
        for (int j = 0; j < N; j++) {
            scanf(" %d", &arr[j]);
        }
        cout << sumOfGCD(N) << endl;
    }
    return 0;
}
