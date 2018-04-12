#include <iostream>
#include <vector>
using namespace std;

int n;
double dist[MAX][MAX];

/*
 *  TSP: Traveling sales person
 *      - optimization problem
 *
 *  path: all paths to current
 *  visited: whether visit or not
 *  currentLength: length of the current path
 *  return shortest Path
 *
 */

double shortestPath(vector<bool>& visit, vector<int>& path, double currentLength) {
    if (path.size() == n)
        return currentLength + dist[path[0]][path.back()];

    double ret = INF;
    // traversal all candidate
    for (int i = 0; i < n; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        path.push_back(i);
        double cand = shortestPath(visit, path, currentLength + dist[path.back()][i]);
        ret = min(ret, cand);
        path.pop_back();
    }
    return ret;
}