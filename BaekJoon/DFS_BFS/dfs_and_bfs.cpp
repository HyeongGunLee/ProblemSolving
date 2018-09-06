#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
queue<int> q;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int start) {
  if (!visited[start]) {
    visited[start] = 1;
    cout << start << " ";
  }

  for (int i = 1; i <= N; i++) {
    if ((graph[start][i] == 1) && (!visited[i])) {
      dfs(graph, visited, i);
    }
  }

}

void bfs(vector<vector<int>>& graph, vector<int>& visited, int start) {
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    cout << temp << " ";
    for (int i = 1; i <= N; i++) {
      if ((graph[temp][i] == 1) && (!visited[i])) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}


int main(void) {
  cin >> N >> M >> V;
  vector<int> visited(N + 1);
  vector<vector<int> > graph(N + 1, vector<int>(N + 1));

  for (int i = 0; i < M; i++) {
    int first, second;
    cin >> first >> second;
    graph[first][second] = 1;
    graph[second][first] = 1;
  }


  dfs(graph, visited, V);
  for (int i = 0; i <= N; i++) {
    visited[i] = 0;
  }
  cout << endl;
  bfs(graph, visited, V);

}