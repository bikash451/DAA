#include<iostream>
#include <list>
using namespace std;

void addEdge(list<int> adj[], int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void DFSUtil(list<int> adj[], int v, bool visited[]) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            DFSUtil(adj, i, visited);
}

bool isConnected(list<int> adj[], int V) {
    bool visited[V] = {false};
    int i;
    for (i = 0; i < V; i++)
        if (!adj[i].empty())
            break;
    if (i == V)
        return true;
    DFSUtil(adj, i, visited);
    for (i = 0; i < V; i++)
        if (!visited[i] && !adj[i].empty())
            return false;
    return true;
}

int isEulerian(list<int> adj[], int V) {
    if (!isConnected(adj, V))
        return 0;
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;
    return (odd)? 1 : 2;
}

void test(list<int> adj[], int V) {
    int res = isEulerian(adj, V);
    if (res == 0)
        cout << "graph is not Eulerian\n";
    else if (res == 1)
        cout << "graph has a Euler path\n";
    else
        cout << "graph has a Euler cycle\n";
}

int main() {
    int V = 5;
    list<int> adj1[V];

    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    test(adj1, V);

    

    return 0;
}

