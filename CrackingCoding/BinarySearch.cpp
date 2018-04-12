#include <iostream>
using namespace std;


bool binarySearchRecursive(int arr[], int x, int left, int right)
{
    if (left > right) return false;

    int mid = left + ((right - left) / 2);

    if (arr[mid] == x) {
        return true;
    } else if (arr[mid] > x) {
        return binarySearchRecursive(arr, x, left, mid - 1);
    } else {
        return binarySearchRecursive(arr, x, mid + 1, right);
    }
}

bool binarySearchIterative(int arr[], int x, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == x) {
            return true;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}


int main(void) {
    int arr[] = {1, 2, 3, 4, 5 ,6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearchRecursive(arr, 10, 0, size-1) << endl;
    cout << binarySearchIterative(arr, 10, size);
    return 0;
}