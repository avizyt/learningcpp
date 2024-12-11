#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

struct EdgeNode
{
    int y, weight;
    EdgeNode *next;
    EdgeNode(int y, int weight = 0, EdgeNode *next = nullptr) : y(y), weight(weight), next(next)
    {
    }
};

// Directed Weighted graph
struct Graph
{
    EdgeNode *edges[101];
    int nvertices;
    bool directed;

    Graph(int nvertices, bool directed = false)
        : nvertices(nvertices), directed(directed)
    {
        for (int i = 0; i < nvertices; i++)
        {
            edges[i] = nullptr;
        }
    }

    void insertEdge(int x, int y, int weight = 0)
    {
        EdgeNode *edge = new EdgeNode(y, weight, edges[x]);
        edges[x] = edge;

        if (!directed)
        {
            EdgeNode *reverseEdge = new EdgeNode(x, weight, edges[y]);
            edges[y] = reverseEdge;
        }
    }

    void printGraph() const
    {
        for (int i = 0; i <= nvertices; i++)
        {
            cout << i << ":";
            EdgeNode *curr = edges[i];
            while (curr != nullptr)
            {
                cout << " -> " << curr->y << "(" << curr->weight << ")";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

// Shortest path algorithm
// Dijkstra

void dijkstra(const Graph &g, int start)
{
    vector<int> dist(g.nvertices + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (EdgeNode *edge = g.edges[u]; edge != nullptr; edge = edge->next)
        {
            int v = edge->y;
            int weight = edge->weight;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distance from node " << start << ":\n";
    for (int i = 1; i <= g.nvertices; i++)
    {
        cout << "Node " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

void dfsComponent(const Graph &g, int v, vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";

    for (EdgeNode *edge = g.edges[v]; edge != nullptr; edge = edge->next)
    {
        int neighbor = edge->y;
        if (!visited[neighbor])
        {
            dfsComponent(g, neighbor, visited);
        }
    }
}

void findConnectedComponents(const Graph &g)
{
    vector<bool> visited(g.nvertices + 1, false);
    int componentCount = 0;

    cout << "Connected Components:\n";
    for (int i = 1; i <= g.nvertices; i++)
    {
        if (!visited[i])
        {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            dfsComponent(g, i, visited);
            cout << endl;
        }
    }
}

int main()
{
    int nvertices = 6;
    Graph g(nvertices);

    // Add edges
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    g.insertEdge(5, 6);

    // Print the graph
    cout << "Graph representation:\n";
    g.printGraph();

    // Find connected components
    findConnectedComponents(g);

    // Compute shortest paths from node 1
    dijkstra(g, 2);

    return 0;
}
