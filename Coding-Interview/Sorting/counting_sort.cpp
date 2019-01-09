#include <iostream>
#include <vector>
using namespace std;


/*
 * k is the maximum number in arr A
 */
void countingSort(vector<int>& A, int k) {
    vector<int> C(k, 0);
    vector<int> B(A);
    int aLen = A.size();
    for (int j = 0; j < aLen; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1];
    }
    for (int j = aLen-1; j >= 0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    A = B;
}

int main(void) {
    vector<int> test{2, 5, 3, 0, 2, 3, 0, 3};
    countingSort(test, 6);
    for (auto i : test) {
        cout << i << " ";
    }
}