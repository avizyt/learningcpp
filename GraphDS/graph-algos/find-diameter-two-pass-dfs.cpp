#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<int>>;

mat tree;
int maxDist = 0;
int farthestNode = 0;

void dfs(int node, int parent, int dist)
{
    if (dist > maxDist)
    {
        maxDist = dist;
        farthestNode = node;
    }
    for (int neighbr : tree[node])
    {
        if (neighbr != parent)
        {
            dfs(neighbr, node, dist + 1);
        }
    }
}

int findDiameter(int n)
{
    maxDist = 0;
    dfs(0, -1, 0);
    int start = farthestNode;
    maxDist = 0;
    dfs(start, -1, 0);
    return maxDist;
}

int main()
{
    int n = 6;
    tree.resize(n);

    tree[0].push_back(1);
    tree[1].push_back(0);

    tree[1].push_back(2);
    tree[2].push_back(1);

    tree[1].push_back(3);
    tree[3].push_back(1);

    tree[3].push_back(4);
    tree[4].push_back(3);

    tree[4].push_back(5);
    tree[5].push_back(4);

    cout << "Diameter of tree: " << findDiameter(n) << endl;
    return 0;
}
