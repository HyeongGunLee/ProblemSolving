#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


int lowest(vector<int>& nums, int l, int h, int target) {
    int result = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] == target) {
            result = mid;
            h = mid-1;
        } else if (nums[mid] > target) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return result;
}

int lastB(vector<int>& nums, int l, int h, int target) {
    int result = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] == target) {
            result = mid;
            l = mid+1;
        } else if (nums[mid] > target) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return result;
}


int main(void) {
    vector<int> test = {1, 3, 3, 4, 5, 5, 5, 6, 7, 8};
    cout << lowest(test, 0, 10, 5) << endl;
    cout << lastB(test, 0, 10, 5) << endl;
}


