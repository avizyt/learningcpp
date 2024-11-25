## Graph Data Structure

### C++ Code Implementation

```cpp
#include <iostream>
#include <vector>

#define MAXV 100 // Maximum number of vertices

// Edge node structure for adjacency list
struct EdgeNode {
    int y;            // Adjacency info
    int weight;       // Edge weight, if any
    EdgeNode* next;   // Pointer to the next edge in the list

    EdgeNode(int y, int weight = 0, EdgeNode* next = nullptr) 
        : y(y), weight(weight), next(next) {}
};

// Graph structure
struct Graph {
    EdgeNode* edges[MAXV + 1]; // Array of adjacency lists
    int degree[MAXV + 1];      // Outdegree of each vertex
    int nvertices;             // Number of vertices in the graph
    int nedges;                // Number of edges in the graph
    bool directed;             // Is the graph directed?

    Graph(int nvertices, bool directed = false) 
        : nvertices(nvertices), nedges(0), directed(directed) {
        for (int i = 0; i <= MAXV; i++) {
            edges[i] = nullptr;
            degree[i] = 0;
        }
    }

    ~Graph() {
        for (int i = 0; i <= MAXV; i++) {
            while (edges[i] != nullptr) {
                EdgeNode* temp = edges[i];
                edges[i] = edges[i]->next;
                delete temp;
            }
        }
    }

    // Add an edge to the graph
    void insertEdge(int x, int y, int weight = 0) {
        EdgeNode* edge = new EdgeNode(y, weight, edges[x]);
        edges[x] = edge;       // Insert at the head of the list
        degree[x]++;

        if (!directed) {
            // Insert the reverse edge for undirected graph
            EdgeNode* reverseEdge = new EdgeNode(x, weight, edges[y]);
            edges[y] = reverseEdge;
            degree[y]++;
        } else {
            nedges++;
        }
    }

    // Print the graph
    void printGraph() const {
        for (int i = 1; i <= nvertices; i++) {
            std::cout << i << ":";
            EdgeNode* current = edges[i];
            while (current != nullptr) {
                std::cout << " -> " << current->y << "(" << current->weight << ")";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
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
```

---

### Explanation of Code

1. **Graph Initialization**:
   - The `Graph` structure initializes with an array of adjacency lists (`edges`) and a degree array (`degree`).
   - The graph can handle up to `MAXV` vertices, with each vertex's adjacency list being stored as a linked list.

2. **Inserting Edges**:
   - The `insertEdge` function creates a new `EdgeNode` and inserts it at the head of the adjacency list for vertex `x`.
   - If the graph is undirected, it also adds the reverse edge.

3. **Printing the Graph**:
   - The `printGraph` function iterates through all vertices and prints their adjacency lists.

4. **Memory Management**:
   - The destructor cleans up all dynamically allocated memory for the adjacency lists to prevent memory leaks.

---

### Example Run
For the example provided in `main`:
- Vertices: 1 through 5
- Edges: (1 → 2), (1 → 3), (2 → 4, weight=10), (3 → 4, weight=20), (4 → 5)

The graph representation will look like:
```
1: -> 3(0) -> 2(0)
2: -> 4(10) -> 1(0)
3: -> 4(20) -> 1(0)
4: -> 5(0) -> 3(20) -> 2(10)
5: -> 4(0)
```

---

### Complexity
- **Insert Edge**: \(O(1)\) per edge (linked list insertion).
- **Print Graph**: \(O(V + E)\), where \(V\) is the number of vertices, and \(E\) is the number of edges.