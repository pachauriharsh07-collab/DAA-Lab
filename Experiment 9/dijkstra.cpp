// Harsh Pachauri(25/DA/030)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5

// Find the vertex with minimum distance
int minDistance(int dist[], bool visited[]){
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++){
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V], int source){
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++){
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++){
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tShortest Distance from Source\n";

    for (int i = 0; i < V; i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}