#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map1;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (map1.find(nums[i]) != map1.end()) {
            int count = map1[nums[i]] + 1;
            if (count > len / 2) {
                return nums[i];
            } else {
                map1[nums[i]] = count;
            }
        } else {
            map1[nums[i]] = 1;
        }
    }
    return nums[0];
}

int main(void) {
}