/*
int n;

int cache[100], S[100];

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;

    for (int i = start+1; i < n; i++) {
        if (S[i] > S[start]) {
            ret = max(ret, 1 + lis(i));
        }
    }
    return ret;
}

*/

#include <iostream>
#include <vector>
using namespace std;

int CeilIndex(vector<int>& v, int l, int r, int key) {
    while (r-l > 1) {
        int m = l + (r-l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}


int lis(vector<int>& v) {
    if (v.size() == 0) return 0;

    vector<int> active(v.size(), 0);
    int length = 1;

    active[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < active[0])
            active[0] = v[i];
        else if (v[i] > active[length-1])
            active[length++] = v[i];
        else
            active[CeilIndex(active, -1, length-1, v[i]))] = v[i];
    }
    return length;
}

int main(void) {
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6};
    cout<< lis(v) << endl;

    return 0;
}