#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int coins[] = {25, 10, 5, 2, 1};
int coinLen = sizeof(coins) / sizeof(coins[0]);

long long makeChange(int coins[], int money, int index, unordered_map<string, long> memo) {
    if (money == 0) return 1;

    if (index > coinLen) return 0;

    string key = money + "-" + index;
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int amountWithCoin = 0;
    long ways = 0;
    while (amountWithCoin <= money) {
        int remaining = money - amountWithCoin;
        ways += makeChange(coins, remaining, index+1, memo);
        amountWithCoin += coins[index];
    }
    memo[key] = ways;
    return ways;

}

int main(void) {

}