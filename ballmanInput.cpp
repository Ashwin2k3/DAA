#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

struct Edge {
    int src, dest, weight;
};

// Function to print the solution
void printSolution(const vector<int>& dist, int V) {
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t";
        if (dist[i] == INF) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
}

// Function that implements Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative-weight cycle." << endl;
            return;
        }
    }

    printSolution(dist, V);
}

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph

    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int src = 0; // Source vertex

    bellmanFord(edges, V, E, src);

    return 0;
}

