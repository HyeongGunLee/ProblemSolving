#include <iostream>
#include <vector>
using namespace std;

int dice[6] = {1, 2, 3, 4, 5, 6};

void diceNumber(int n, int& count, int sum, vector<int>& list) {
    if (n == sum) {
        count++;
    }

    for (int i = 0; i < 6; i++) {
        if (dice[i] <= n - sum) {
            list.push_back(dice[i]);
            diceNumber(n, count, sum + dice[i], list);
            list.pop_back();
        }
    }
}

long long cache[10001];

int countNum(int n) {
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    cache[4] = 8;
    cache[5] = 16;
    for (int i = 6; i <= n; i++) {
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3] + cache[i-4] + cache[i-5];
    }
    return cache[n];
}


int main(void) {
    cout << countNum(610) << endl;
}