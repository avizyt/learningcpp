#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>
#include <fstream>
#include <iostream>

using namespace std;

struct Edge
{
    int u, v, weight;
    Edge(int u, int v, int weight) : u(v), v(v), weight(weight) {}
};

struct UnionFind
{
    vector<int> parent, rank;

    UnionFind(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return false;
        if (rank[rootx] > rank[rooty])
        {
            parent[rooty] = rootx;
        }
        else if (rank[rootx] < rank[rooty])
        {
            parent[rootx] = rooty;
        }
        else
        {
            parent[rooty] = rootx;
            rank[rootx]++;
        }

        return true;
    }
};

int main()
{
    ifstream input("..\\data\\railroad.txt"); // Update the file path as needed
    if (!input)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    cin.rdbuf(input.rdbuf());

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];

    set<pair<int, int>> forbidden;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        forbidden.insert({u, v});
    }

    // prepare edges for MST calculation
    vector<Edge> edges;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (forbidden.find({i, j}) == forbidden.end())
            {
                edges.emplace_back(i, j, a[i] + a[j]);
            }
        }
    }

    vector<int> results(n + 1, INT_MAX);

    for (int prison = 1; prison <= n; ++prison)
    {
        UnionFind uf(n);
        int mst_cost = 0;
        int components = n - 1;

        // calculate MST excluding prison
        for (const auto &edge : edges)
        {
            if (edge.u == prison || edge.v == prison)
                continue;
            if (uf.unite(edge.u, edge.v))
            {
                mst_cost += edge.weight;
                components--;
            }
        }

        // check if all other states are connected
        if (components > 1)
        {
            results[prison] = -1;
        }
        else
        {
            results[prison] = mst_cost;
        }
    }

    // print results
    for (int i = 0; i <= n; ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}
