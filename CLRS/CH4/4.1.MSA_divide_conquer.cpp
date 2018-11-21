#include <iostream>
#include <vector>
using namespace std;

/*
 *  Maximum subarray problem
 */

class MSA {
public:
    int low;
    int high;
    int arraySum;

    MSA(int l, int h, int s) {
        low = l;
        high = h;
        arraySum = s;
    }

    MSA() {

    }
};

MSA findMaxCrossingSubarray(vector<int>& A, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = -1;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (left_sum < sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int max_right = -1;
    for (int i = mid+1; i <= high; i++) {
        sum += A[i];
        if (right_sum < sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    MSA result(max_left, max_right, left_sum + right_sum);
    return result;
}

MSA findMaxSubarray(vector<int>& A, int low, int high) {
//    int mid = (low + high) / 2;
    if (low == high) {
        MSA result(low, high, A[low]);
        return result;
    } else {
        int mid = (low + high) / 2;
        MSA left_result = findMaxSubarray(A, low, mid);
        MSA right_result = findMaxSubarray(A, mid+1, high);
        MSA cross_result = findMaxCrossingSubarray(A, low, mid, high);
        if ((left_result.arraySum >= right_result.arraySum) && (left_result.arraySum >= cross_result.arraySum)) {
            return left_result;
        } else if ((right_result.arraySum >= left_result.arraySum) && (right_result.arraySum >= cross_result.arraySum)) {
            return right_result;
        } else {
            return cross_result;
        }
    }

}


int main(void) {
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> A(arr, arr + n);
    MSA test_result;
    test_result = findMaxSubarray(A, 0, 15);
    cout << test_result.low << " " << test_result.high << endl;

}
