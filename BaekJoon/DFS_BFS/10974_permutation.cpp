#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N;
vector<bool> visited;
vector<int> nums;

void permutation(int cur) {
    if (cur == N) {
        for (int i = 0; i < N; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            nums.push_back(i+1);
            permutation(cur+1);
            visited[i] = false;
            nums.pop_back();

        }
    }
}

int main(void) {
    cin >> N;
    visited = vector<bool>(N, false);
    permutation(0);
}
