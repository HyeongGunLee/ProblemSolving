#include <iostream>
#include <list>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph {
private:
    int V;
    list <iPair> *adj;
public:
    Graph (int V);
    ~Graph(){}
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
    void printParent(int parent[], int s);
};


Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int s) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, s));
    dist[s] = 0;
    int parent[V];
    parent[s] = -1;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        list<iPair>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int weight = it->second;
            if (dist[v] > dist[u] + weight) {
                parent[v] = u;
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << i << " distance:" << dist[i] << endl;
        cout << "ShortestPAth: ";
        printParent(parent, i);
        cout << endl;
    }

}

void Graph::printParent(int *parent, int s) {
    if (parent[s] == -1) {
        return;
    }
    printParent(parent, parent[s]);
    cout << s << " ";
}


// vector of pairs
void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void printPath(int parent[], int s) {
    if (parent[s] == -1) {
        return;
    }

    printPath(parent, parent[s]);
    cout << s << " ";
}

void shortestPath(vector <pair<int, int>> adj[], int s, int V) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    int parent[V];
    parent[s] = -1;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                parent[v] = u;
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }

        }
    }
    for (int i = 0; i < V; i++) {
        cout << i << " Distance: " << dist[i] << endl;
        printPath(parent, i);
        cout << endl;
    }
}


int main()
{

    /*
     *  Graph Representation
     */
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    cout << "Graph" << endl;
    g.shortestPath(0);
    cout << endl;
    /*
     *  Vector Representation
     */
    vector <iPair> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    cout << "Vector" << endl;
    shortestPath(adj, 0, V);
    return 0;
}
