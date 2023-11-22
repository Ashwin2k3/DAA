#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& shortestPathSet, int V) {
    int min = INF, minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!shortestPathSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the solution
void printSolution(const vector<int>& dist, int V) {
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF); // The output array to hold the shortest distance to each vertex
    vector<bool> shortestPathSet(V, false); // shortestPathSet[i] will be true if vertex i is included in the shortest path tree

    dist[src] = 0; // Distance from the source vertex to itself is always 0

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, shortestPathSet, V);

        shortestPathSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!shortestPathSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    int src = 0;
    dijkstra(graph, src);

    return 0;
}

