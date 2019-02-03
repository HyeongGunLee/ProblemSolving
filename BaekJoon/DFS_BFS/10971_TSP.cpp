#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int W[11][11];
int minPath = 987654321;

//int tsp(vector<int>& path, vector<bool>& visited, int last) {
//    if (path.size() == N) {
//        if (W[last][1]) return W[last][1];
//        else return INT_MAX;
//    }
//
//    int ret = INT_MAX;
//    for (int i = 1; i <= N; i++) {
//        if (!visited[i] && W[last][i]) {
//
//            visited[i] = true;
//            path.push_back(i);
//            ret = min(ret, tsp(path, visited, i) + W[last][i]);
//            path.pop_back();
//            visited[i] = false;
//        }
//    }
//    return ret;
//}

void dfs(vector<bool>& visited, int node, int cost, int cnt) {
    if (cnt == N-1 && W[node][1]) {
        minPath = min(minPath, cost + W[node][1]);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && W[node][i]) {
            visited[i] = true;
            dfs(visited, i, cost+W[node][i], cnt+1);
            visited[i] = false;
        }
    }
}


int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }

    vector<bool> visited(N, false);
    visited[1] = true;

    dfs(visited, 1, 0, 0);
    cout << minPath << endl;
    return 0;
}
