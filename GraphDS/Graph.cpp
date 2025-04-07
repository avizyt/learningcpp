#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// maximum number of vertices
#define MAXV 100

// Edge node for adj list
struct EdgeNode
{
    // adj
    int y;
    // edge weight
    int weight;

    // pointer to the next edge in the list
    EdgeNode *next;

    EdgeNode(int y, int weight = 0, EdgeNode *next = nullptr)
        : y(y), weight(weight), next(next) {}
};

// Graph Structure
struct Graph
{
    // array of adj list
    EdgeNode *edges[MAXV + 1];

    // out degree of each vertex
    int degree[MAXV + 1];

    // number of vertices in the graph
    int nvertices;

    // number of edges on the graph
    int nedges;

    // Is the graph directed?
    int directed;

    Graph(int nvertices, bool directed = false)
        : nvertices(nvertices), nedges(0), directed(directed)
    {
        for (int i = 0; i <= MAXV; i++)
        {
            edges[i] = nullptr;
            degree[i] = 0;
        }
    }

    ~Graph()
    {
        for (int i = 0; i <= MAXV; i++)
        {
            while (edges[i] != nullptr)
            {
                EdgeNode *temp = edges[i];
                edges[i] = edges[i]->next;
                delete temp;
            }
        }
    }

    // add edge to the graph
    void insertEdge(int x, int y, int weight = 0)
    {
        EdgeNode *edge = new EdgeNode(y, weight, edges[x]);
        // insert at the head of the list
        edges[x] = edge;
        degree[x]++;

        if (!directed)
        {
            // insert reverse edge for undirected graph
            EdgeNode *reverseEdge = new EdgeNode(x, weight, edges[y]);
            edges[y] = reverseEdge;
            degree[y]++;
        }
        else
        {
            nedges++;
        }
    }

    // Display graph
    void printGraph() const
    {
        for (int i = 0; i <= nvertices; i++)
        {
            cout << i << ":";
            EdgeNode *current = edges[i];
            while (current != nullptr)
            {
                std::cout << " -> " << current->y << "(" << current->weight << ")";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

/* Graph Traversal Algorithms

1. Depth First Search : Use Stack or Recursion
    - For Finding Path
2. Breadth First Search : Use Queue
    - For Shortest Path
*/

void dfsearch(Graph g, int start)
{
    vector<bool> visited(g.nvertices + 1, false);
    vector<int> stk;

    visited[start] = true;
    stk.push_back(start);

    cout << "DFS Traversal: ";
    while (!stk.empty())
    {
        int v = stk.back();
        stk.pop_back();
        cout << v << " ";

        EdgeNode *current = g.edges[v];
        while (current != nullptr)
        {
            if (!visited[current->y])
            {
                visited[current->y] = true;
                stk.push_back(current->y);
            }
            current = current->next;
        }
    }
    cout << endl;
}

void bfsearch(Graph g, int start)
{
    vector<bool> visited(g.nvertices + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int v = q.front();

        q.pop();
        cout << v << " ";

        EdgeNode *current = g.edges[v];
        while (current != nullptr)
        {
            if (!visited[current->y])
            {
                visited[current->y] = true;
                q.push(current->y);
            }
            current = current->next;
        }
    }
    cout << endl;
}

void bfsHelper(Graph g, int start, vector<bool> &visited)
{
    vector<int> queue; // Queue for BFS
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty())
    {
        int v = queue.front();
        queue.erase(queue.begin());
        cout << v << " "; // Print the node

        EdgeNode *current = g.edges[v];
        while (current != nullptr)
        {
            if (!visited[current->y])
            {
                visited[current->y] = true;
                queue.push_back(current->y);
            }
            current = current->next;
        }
    }
}
void findConnectedComponent(Graph g)
{
    vector<bool> visited(g.nvertices + 1, false);
    int componentCount = 0;
    cout << "Connected Component";
    for (int i = 1; i <= g.nvertices; i++)
    {
        if (!visited[i])
        {
            componentCount++;
            cout << "Component: " << componentCount;
            bfsHelper(g, i, visited);
            cout << endl;
        }
    }
}

int main()
{
    int nvertices = 8; // Number of vertices
    Graph g(nvertices);

    // Graph 1
    // g.insertEdge(1, 2);
    // g.insertEdge(1, 3);
    // g.insertEdge(2, 4, 10);
    // g.insertEdge(3, 4, 20);
    // g.insertEdge(4, 5);

    // Graph 2
    // g.insertEdge(1, 2);
    // g.insertEdge(1, 3);
    // g.insertEdge(2, 4);
    // g.insertEdge(3, 4);
    // g.insertEdge(3, 5);
    // g.insertEdge(4, 6);
    // g.insertEdge(4, 7);
    // g.insertEdge(5, 8);
    // g.insertEdge(5, 9);

    // Graph 3
    g.insertEdge(1, 2);
    g.insertEdge(1, 7);
    g.insertEdge(1, 8);
    g.insertEdge(2, 3);
    g.insertEdge(2, 5);
    g.insertEdge(3, 5);
    g.insertEdge(3, 4);
    g.insertEdge(5, 4);
    g.insertEdge(5, 6);

    // Printing the graph
    std::cout << "Graph representation:" << std::endl;
    g.printGraph();

    dfsearch(g, 1); // Start DFS from vertex 1
    bfsearch(g, 1);
    findConnectedComponent(g);

    return 0;
}
