// Harsh Pachauri(25/DA/030)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Find parent of a vertex
int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

// Union two sets
void unionSet(vector<int>& parent, vector<int>& rank,
              int u, int v) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;
    }
}

void kruskalMST(vector<Edge>& edges, int V) {

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalWeight = 0;
    int edgeCount = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge edge : edges) {

        int u = findParent(parent, edge.u);
        int v = findParent(parent, edge.v);

        // If no cycle
        if (u != v) {

            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.weight << endl;

            totalWeight += edge.weight;
            edgeCount++;

            unionSet(parent, rank, u, v);

            if (edgeCount == V - 1)
                break;
        }
    }

    cout << "Total Weight = "
         << totalWeight << endl;
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}
