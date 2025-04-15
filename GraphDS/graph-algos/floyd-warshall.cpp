#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9; // Use a large value to represent infinity

void floydWarshall(vector<vector<int>> &graph, int V)

/*
We maintain a distance matrix dist[i][j], where each entry is the shortest distance
 from node i to node j.

 The key idea is:

 For every node k, try to improve the distance
 from i to j by checking if going through k is better.

 Formula:
 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
*/

{
    vector<vector<int>> dist = graph;

    // Core Floyd-Warshall triple loop
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < V; ++i)
    {
        if (dist[i][i] < 0)
        {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    // Print final shortest distances
    cout << "All-pairs shortest path matrix:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int V = 5;
    // vector<vector<int>> graph = {
    //     {0, 5, INF, 10},
    //     {INF, 0, 3, INF},
    //     {INF, INF, 0, 1},
    //     {INF, INF, INF, 0}};

    vector<vector<int>> graph = {
        {0, 5, INF, 9, 1},
        {5, 0, 2, INF, INF},
        {INF, 2, 0, 7, INF},
        {9, INF, 7, 0, 2},
        {1, INF, INF, 2, 0}};

    floydWarshall(graph, V);
    return 0;
}
