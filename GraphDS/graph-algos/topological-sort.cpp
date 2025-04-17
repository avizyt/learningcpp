#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, st, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSort(V, adj);

    cout << "Topological Sort: ";
    for (int node : topo)
        cout << node << " ";
}