#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left+right)/2];
    while (left < right) {
        while ((arr[left] < pivot) && (left < right))
            left++;
        while ((arr[right] > pivot) && (left < right))
            right--;

        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    return left;
}


void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int partitionIndex = partition(arr, left, right);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}


int main(void) {
    int test[6] = {6, 4, 3, 2, 1, 5};
    int n = sizeof(test) / sizeof(test[0]);
    vector<int> arr(test, test + n);
    quickSort(arr, 0, n-1);
    for (int a : arr) {
        cout << a << " ";
    }
}