#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int nums_len = nums.size();
        pair<int, int> largest;
        int lar_num = -1;
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > lar_num) {
                lar_num = nums[i];
                largest.first = i;
                largest.second = lar_num;
            }
        }

        for (int i = 0; i < nums_len; i++) {
            if (i != largest.first && (nums[i]*2) > largest.second) {
                return -1;
            }
        }
        return largest.first;
    }
};

int main(void) {
    Solution* test = new Solution();
    int arr[5] = {1, 2, 3, 4};
    vector<int> vec1(arr, arr + sizeof(arr) / sizeof(int));
    cout << test->dominantIndex(vec1) << endl;
}

