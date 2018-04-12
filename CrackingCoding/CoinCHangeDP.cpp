

/// O(mn)
// Min number of coins
class Solution {
public:

    int minCoins(vector<int>& coins, int len, int amount) {
        if (amount == 0) return 0;

        int res = INT_MAX;

        for (int i = 0; i < len; i++) {
            if (coins[i] <= amount) {
                int sub_res = minCoins(coins, len, amount-coins[i]);
                if (sub_res != INT_MAX && sub_res + 1 < res)
                    res = subres + 1;
            }
        }
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        return minCoins(coins, len, amount)
    }
};

/// recursive. exponential
// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // base case
    if (V == 0) return 0;

    // Initialize result  int res = INT_MAX;

    // Try every coin that has smaller value than V
    for (int i=0; i<m; i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(coins, m, V-coins[i]);

            // Check for INT_MAX to avoid overflow and see if
            // result can minimized
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}








/// 가능한 갯수

#include <iostream>
using namespace std;


// Recursive 갯수 구하는거
// count(s, size, amount)
int count(int s[], int index, int amount) {
    if (amount == 0)
        return 1;

    if (amount < 0)
        return 0;

    if (index <= 0 && amount > 0)
        return 0;

    return count(s, index-1, amount) + count(s, index, amount - s[index-1]);
}


// DP solution
int countDP(int s[], int index, int amount) {
    int table[amount+1];
    memset(table, 0, sizeof(table));

    table[0] = 1;

    for (int i = 0; i < index; i++) {
        for (int j=s[i]; i <= amount; i++) {
            table[j] += table[j-s[i]];
        }
    }
    return table[amount];
}



int main(void) {

}

