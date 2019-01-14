#include <iostream>
#include <limits.h>
using namespace std;

#define V 9


int minDistance(int dist[V], bool sptSet[V]) {
    int minVal = INT_MAX;
    int result;
    for (int i = 0; i < V; i++) {
        if (sptSet[i] == false && dist[i] <= minVal) {
            minVal = dist[i];
            result = i;
        }
    }
    return result;
}

void printSolution(int dist[]) {
    for (int i = 0; i < V; i++) {
        cout << "Start: 0 to " << i << " distance: " << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int start) {
    bool sptSet[V];
    int dist[V];

    for (int i = 0; i < V; i++) {
        sptSet[i] = false;
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < V-1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);
    return 0;
}


