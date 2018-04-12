#include <iostream>
#include <vector>
using namespace std;

/// find minimun element in a sorted and rotated array

int findMinimun(vector<int>& nums, int l, int h) {
    if (l > h) return nums[0];

    if (h == l) return nums[l];

    int mid = l + (h - l) / 2;

    if (mid < h && nums[mid] > nums[mid+1])
        return nums[mid+1];

    if (mid > l && nums[mid] < nums[mid-1])
        return nums[mid];

    if (nums[h] > nums[mid])
        return findMinimun(nums, l, mid-1);
    return findMinimun(nums, mid+1, h);

}


/// pivot
int findPivot(int arr[], int low, int high)
{
    // base cases
    if (high < low)  return -1;
    if (high == low) return low;

    int mid = (low + high)/2;   /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid-1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid-1);
    return findPivot(arr, mid + 1, high);
}




/// search element sorted and rotated

int findSandR(vector<int>& nums, int l, int h, int target) {
    if (l > h) return -1;

    int mid = l + (h - l) / 2;

    if (nums[mid] == target)
        return mid;

    // l ~ mid is sorted
    if (nums[l] <= nums[mid]) {
        if (target >= nums[l] && target <= nums[mid])
            return findSandR(nums, l, mid-1, target);
        return findSandR(nums, mid+1, h, target);
    }

    // mid ~ r is sorted
    if (target >= nums[mid] && target <= nums[h])
        return findSandR(nums, mid+1, h, target);
    return findSandR(nums, l, mid-1, target);
}

int main(void) {

}