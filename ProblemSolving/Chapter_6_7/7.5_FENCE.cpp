#include <vector>
#include <iostream>
using namespace std;

/* O(n^2)
int bruteforce(vector<int>& h) {
    int ret = 0;
    int N = h.size();
    for (int left = 0; left < N; left++) {
        int minHeight = h[left];
        for (int right = left; right < N; right++)
            minHeight = min(minHeight, h[right]);
        ret = max(ret, minHeight * (right - left + 1));
    }
}
}
 */


// divide and conquer
vector<int> h;

int solve(int left, int right) {
    if (left == right) return h[left];

    int ret = 0;
    int mid = (left + right) / 2;

    ret = max(solve(left, mid), solve(mid+1, right));

    int lo = mid, hi = mid + 1;
    int height = max(h[lo], h[hi]);

    while(left < lo || hi < right) {
        if (hi < right && (lo == left || h[lo-1] < h[hi+1])) {
            ++hi;
            height = min(height, h[hi]);
        } else {
            --lo;
            height = min(height, h[lo]);
        }
        ret = max(ret, (right-left+1) * height);
    }
    return ret;
}
