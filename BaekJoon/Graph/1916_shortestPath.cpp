#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


typedef pair<int, int> iPair;

int N, M;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
//    adj[v].push_back(make_pair(u, w));
}

void shortestPath(vector<pair<int, int>> adj[], int start, int end) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(N, INT_MAX);
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

//    for (int i = 0; i < N; i++) {
//        cout << i << " distance: " << dist[i] << endl;
//    }
    cout << dist[end] << endl;
}

int main(void) {
    cin >> N;
    cin >> M;
    vector<iPair> adj[N];
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u-1, v-1, w);
    }
    int start, end;
    cin >> start >> end;

    shortestPath(adj, start-1, end-1);
}

