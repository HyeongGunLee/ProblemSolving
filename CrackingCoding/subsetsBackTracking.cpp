#include <iostream>
#include <vector>
using namespace std;


void subsetHelp(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index) {
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        result.push_back(subset);
        subsetHelp(nums, result, subset, i + 1);
        subset.pop_back();
    }
    return;
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    result.push_back(subset);
    subsetHelp(nums, result, subset, 0);
    return result;
}

int main(void) {

}