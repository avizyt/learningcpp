#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class UnionFind
{

    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v)
    {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV)
            return false;

        // union by rank
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;

        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }

    void getRankList()
    {
        cout << "Rank of Nodes" << endl;
        for (int item : rank)
        {

            cout << item << endl;
        }
    }
    void getParentList()
    {
        cout << "Parent Node" << endl;
        for (int item : parent)
        {

            cout << item << endl;
        }
    }
};

int main()
{
    int n = 4, m = 4;
    vector<Edge> edges = {
        {1, 2, 3},
        // {1, 3, 1},
        {2, 3, 2},
        {3, 4, 4},
        {2, 4, 6}};

    sort(edges.begin(), edges.end());
    UnionFind uf(n + 1);

    int mst_cost = 0;
    vector<Edge> mst;

    for (Edge &edge : edges)
    {
        if (uf.unionSets(edge.u, edge.v))
        {
            mst_cost += edge.weight;
            mst.push_back(edge);
        }
    }
    uf.getRankList();
    uf.getParentList();
    cout << "MST Cost: " << mst_cost << endl;
    cout << "MST Edges:\n";
    for (Edge &edge : mst)
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";

    return 0;
}
