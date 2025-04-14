#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;              // Max number of nodes
vector<int> adj[N];             // Adjacency list
vector<bool> visited(N, false); // Visited array

void dfs(int startnode)
{
    visited[startnode] = true;
    cout << startnode << " ";

    for (int neighbor : adj[startnode])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter number nodes and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Omit this line for directed graph
    }

    // adj[1].push_back(2);
    // adj[1].push_back(4);
    // adj[2].push_back(3);
    // adj[2].push_back(5);
    // adj[5].push_back(3);

    int startNode;
    cout << "Enter starting node for DFS: ";
    cin >> startNode;
    // int startnode = 1;

    cout << "DFS traversal starting from node " << startNode << ": ";
    dfs(startNode);
    cout << "\n";

    return 0;
}