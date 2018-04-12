#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int map[1001][1001] = { 0, };
bool visited[1001] = {0, };


void dfs(int start) {
    if (!visited[start]) {
        visited[start] = true;
        cout << start << " ";
    }

    for (int i = 0; i < 1001; i++) {
        if (map[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (int i = 0; i < 1001; i++) {
            if (map[temp][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        map[start][end] = 1;
        map[end][start] = 1;
    }

    dfs(V);
    cout << endl;

    for (int i = 0; i < 1001; i++) {
        visited[i] = 0;
    }


    bfs(V);

}