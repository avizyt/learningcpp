#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

// Union-Find structure for cycle detection
struct UnionFind
{
    vector<int> parent, rank;

    UnionFind(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
            }
            else if (rank[rootx] > rank[rooty])
            {
                parent[rooty] = rootx;
            }
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
};

// function to find MST using Kruskal's Algorithm
int kruskalMST(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    UnionFind uf(n);

    int mstCost = 0;
    for (const auto &edge : edges)
    {
        if (uf.find(edge.u) != uf.find(edge.v))
        {
            uf.unionSets(edge.u, edge.v);
            mstCost += edge.weight;
        }
    }
    return mstCost;
}

int main()
{
    ifstream inputFile("kruskal_input.txt");

    if (!inputFile)
    {
        cerr << "Error: Unable to open file.\n";
        return 1;
    }
    int n, m;
    inputFile >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        inputFile >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    inputFile.close();

    int mstCost = kruskalMST(n, edges);
    cout << "The cost of the Minimum Spanning Tree is: " << mstCost << endl;
    return 0;
}
