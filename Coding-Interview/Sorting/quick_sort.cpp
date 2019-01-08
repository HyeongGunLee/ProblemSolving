#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    int temp;
    for (int j = p; j < r; j++) {
        if (arr[j] < x) {
            i = i + 1;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[r];
    arr[r] = arr[i+1];
    arr[i+1] = temp;
    return i+1;
}

int random_partition(vector<int>& arr, int p, int r) {
    int i = rand()% (r-p+1) + p;
    int temp = arr[r];
    arr[r] = arr[i];
    arr[i] = temp;
    return partition(arr, p, r);
}

void quickSort(vector<int>& arr, int p, int r) {
    if (p < r) {
//        int q = partition(arr, p, r);
        int q = random_partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int main(void) {
    vector<int> test{3, 4, 1, 2, 5};
    quickSort(test, 0, 4);
    for (int &i : test) {
        cout << " " << i <<endl;
    }

    for (auto i : test) {
        cout << i << endl;
    }

}
