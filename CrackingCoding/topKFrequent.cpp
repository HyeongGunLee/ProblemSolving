#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second > p2.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    map<int, int> map1;
    int size = nums.size();
    for (int i = 0; i < size-1; i++) {
        int count = 1;
        while (nums[i] == nums[i+1] && i < size-1) {
            count++;
            i++;
        }
        map1[nums[i-1]] = count;
    }
    map<int, int>::iterator it = map1.begin();
    for (int i = 0; i < k; i++) {
        result.push_back(it->first);
        it++;
    }
    return result;
}


int main(void) {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    vector<int> result = topKFrequent(arr, 2);
    for (int i = 0; i < 5; i++) {
        cout << result[i] << endl;
    }
}