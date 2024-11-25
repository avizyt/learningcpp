### **Understanding the Problem**

We are tasked to use **Kruskal's Algorithm** on a graph to find the **Minimum Spanning Tree (MST)**. We'll also explain the **Union-Find data structure**, which is used to efficiently detect cycles in the graph.

---

### **Input Graph**

**Nodes**: \( 1, 2, 3, 4 \)

**Edges**:
1. \( (1, 2) \) → weight \( 3 \)
2. \( (1, 3) \) → weight \( 1 \)
3. \( (2, 3) \) → weight \( 2 \)
4. \( (3, 4) \) → weight \( 4 \)
5. \( (2, 4) \) → weight \( 6 \)

---

### **Graph Visualization**

Here’s how the graph looks:

```
       (3)
   1 ------- 2
    \       / \
     \(1)  /   \(6)
      \   /     \
       3 ------- 4
         \(4)
```

- Each edge is labeled with its weight.

---

### **Union-Find Data Structure**

The **Union-Find (Disjoint-Set Union)** data structure is used to:
1. **Track connected components** of the graph.
2. **Efficiently detect cycles** while adding edges.

#### **Key Operations**
1. **Find**: Determines the root (or parent) of a node.
   - Path compression is applied to speed up future operations.
2. **Union**: Combines two components into one.
   - Union by rank or size ensures the tree remains balanced.

---

### **Step-by-Step Kruskal's Algorithm**

#### **Input**
Graph edges sorted by weight:
1. \( (1, 3) \) → weight \( 1 \)
2. \( (2, 3) \) → weight \( 2 \)
3. \( (1, 2) \) → weight \( 3 \)
4. \( (3, 4) \) → weight \( 4 \)
5. \( (2, 4) \) → weight \( 6 \)

#### **Process**
We iterate over the sorted edges, adding them to the MST if they don’t form a cycle. Union-Find helps us check for cycles.

1. **Add \( (1, 3) \)**
   - Components: \( \{1\}, \{2\}, \{3\}, \{4\} \)
   - Add edge → Union(1, 3)
   - MST: \( \{(1, 3)\} \), Cost: \( 1 \)

2. **Add \( (2, 3) \)**
   - Components: \( \{1, 3\}, \{2\}, \{4\} \)
   - Add edge → Union(2, 3)
   - MST: \( \{(1, 3), (2, 3)\} \), Cost: \( 1 + 2 = 3 \)

3. **Skip \( (1, 2) \)**
   - Components: \( \{1, 2, 3\}, \{4\} \)
   - Adding edge forms a cycle → Skip.

4. **Add \( (3, 4) \)**
   - Components: \( \{1, 2, 3\}, \{4\} \)
   - Add edge → Union(3, 4)
   - MST: \( \{(1, 3), (2, 3), (3, 4)\} \), Cost: \( 1 + 2 + 4 = 7 \)

5. **Skip \( (2, 4) \)**
   - Components: \( \{1, 2, 3, 4\} \)
   - Adding edge forms a cycle → Skip.

---

### **Union-Find Implementation in Code**

#### **Code Explanation**
- **Find**: Uses path compression for efficient root retrieval.
- **Union**: Merges two components, using rank for efficiency.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;

        // Union by rank
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

int main() {
    int n = 4, m = 5;
    vector<Edge> edges = {
        {1, 2, 3},
        {1, 3, 1},
        {2, 3, 2},
        {3, 4, 4},
        {2, 4, 6}
    };

    sort(edges.begin(), edges.end());
    UnionFind uf(n + 1); // 1-based indexing

    int mst_cost = 0;
    vector<Edge> mst;

    for (Edge &edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mst_cost += edge.weight;
            mst.push_back(edge);
        }
    }

    cout << "MST Cost: " << mst_cost << endl;
    cout << "MST Edges:\n";
    for (Edge &edge : mst)
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";

    return 0;
}
```

---

### **Output**
For the input graph:

```
4 5
1 2 3
1 3 1
2 3 2
3 4 4
2 4 6
```

**Output**:
```
MST Cost: 7
MST Edges:
1 - 3 (Weight: 1)
2 - 3 (Weight: 2)
3 - 4 (Weight: 4)
```

---

### **When to Use MST**
Use MST in problems where:
1. **You need to connect all nodes with minimum cost.**
2. **The graph is connected (or can be made connected).**
3. **Applications:**
   - Network design: Cable, roads, or pipelines.
   - Approximation in problems like the Traveling Salesman Problem.