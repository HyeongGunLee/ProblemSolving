#include <iostream>
using namespace std;


int N, M;
int graph[1001][1001];
int visited[1001];

void visit(int index) {
    for (int i = 1; i <= N; i++) {
        if (graph[index][i] == 1 && !visited[i]) {
            visited[i] = 1;
            visit(i);
        }
    }
}

int main(void) {
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int connected = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            connected += 1;
            visit(i);
        }
    }
    cout << connected << endl;
}

