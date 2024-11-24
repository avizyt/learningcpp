#include <iostream>
#include <vector>

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

int main()
{
    int nvertices = 5; // Number of vertices
    Graph g(nvertices);

    // Adding edges
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 4, 10);
    g.insertEdge(3, 4, 20);
    g.insertEdge(4, 5);

    // Printing the graph
    std::cout << "Graph representation:" << std::endl;
    g.printGraph();

    return 0;
}
