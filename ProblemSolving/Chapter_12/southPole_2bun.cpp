#include <iostream>
#include <vector>
#include <queue>
using namespace std;

double dist[101][101];
int n;

bool decision(double d) {
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int seen = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        ++seen;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[here][i] <= d) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return n == seen;
}

double optimize() {
    double lo = 0, hi = 1416;
    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}


int main(void) {
}