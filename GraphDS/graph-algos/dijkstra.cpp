#include <bits/stdc++.h>

using namespace std;
using Pair = pair<int, int>;

const int INF = numeric_limits<int>::max();

void printPath(int node, const vector<int> &parent)
{
    if (parent[node] == -1)
    {
        cout << node << " ";
        return;
    }
    printPath(parent[node], parent);
    cout << node << " ";
}

// graph as adjacency list: pair<neighbor,weight>
void dijkstra(int V, vector<Pair> adj[], int source)
{

    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[source] = 0;

    // min-heap: pair<distance, node>
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Optimization: skip if we already found a better path
        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u; // Track how we reached v
                pq.push({dist[v], v});
            }
        }
    }

    // Print distances and paths
    cout << "Shortest distances and paths from source " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "To " << i << " -> Distance: ";
        if (dist[i] == INF)
        {
            cout << "∞ | No path\n";
        }
        else
        {
            cout << dist[i] << "   | Path: ";
            printPath(i, parent);
            cout << "\n";
        }
    }
}

int main()
{
    int V = 5;
    vector<Pair> adj[V];

    // Sample directed graph
    adj[0].push_back({1, 5});
    adj[0].push_back({3, 9});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 7});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}