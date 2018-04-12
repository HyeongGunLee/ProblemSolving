#include <iostream>
#include <queue>
#include <cstdio>
#include <functional>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> arr;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        scanf(" %d", &temp);
        arr.push(temp);
    }

    while (!arr.empty()) {
        printf("%d\n", arr.top());
        arr.pop();
    }


}