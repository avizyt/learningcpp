#include <bits/stdc++.h>
// #include <include/extra_utils.h>
using namespace std;

// type alias for readabilty
using Edge = tuple<int, int, int>;

void bellmanFord(int V, int E, vector<Edge> &edges, int source)
{
    vector<int> dist(V + 1, INT_MAX); // Assuming nodes are 1-indexed
    dist[source] = 0;

    // Step 1: Relax all edges (V - 1) times
    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for (auto &[u, v, w] : edges)
    {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    // Step 3: Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

bool readGraphFromFile(const string &filename, int &V, int &E, vector<Edge> &edges, int &source)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    infile >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        infile >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    infile >> source;

    infile.close();
    return true;
}

int main()
{
    int V, E, source;
    vector<Edge> edges;

    string filename = "./inputs.txt";
    if (!readGraphFromFile(filename, V, E, edges, source))
    {
        return 1;
    }

    bellmanFord(V, E, edges, source);

    return 0;
}