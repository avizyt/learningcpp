/*
Breadth-First Search (BFS)
Approach:

Starts from a vertex and explores all its neighbors before moving on to the next level of vertices.
Think of it as exploring "breadth" first (like layers).

Algorithm:

Use a queue to keep track of vertices.
Mark the visited vertices to avoid cycles.

Time Complexity: O(V+E), where V is the number of vertices, and E is the number of edges.

Space Complexity:O(V) (for the queue)

Example Use Case:

Shortest path in an unweighted graph.
Finding connected components.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    int n = 6; // Number of vertices
    vector<vector<int>> graph(n + 1);

    // Example graph: undirected
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 5};
    graph[4] = {2, 6};
    graph[5] = {3};
    graph[6] = {4};

    vector<bool> visited(n + 1, false);
    cout << "BFS Traversal: ";
    bfs(1, graph, visited); // Start from node 1
    return 0;
}