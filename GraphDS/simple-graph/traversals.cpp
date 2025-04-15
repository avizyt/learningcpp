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

void dfsStack(int start)
{
    stack<int> st;
    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << node << " ";

            // push neighbor to stack in reverse order for consistency
            for (int i = adj[node].size() - 1; i >= 0; --i)
            {
                int neighbor = adj[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{

    /* for dfs:
    Enter number of nodes and edges: 5 4
    Enter edges (u v):
    1 2
    1 3
    2 4
    3 5
    Enter starting node for DFS: 1

    for bfs:
    Enter number of nodes and edges: 6 5
    Enter edges (u v):
    1 2
    1 3
    2 4
    3 5
    5 6
    Enter starting node for BFS: 1


    */
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

    int startNode;
    cout << "Enter starting node for DFS: ";
    cin >> startNode;
    // int startnode = 1;

    cout << "DFS traversal starting from node " << startNode << ": ";
    bfs(startNode);

    cout << "\n";

    return 0;
}