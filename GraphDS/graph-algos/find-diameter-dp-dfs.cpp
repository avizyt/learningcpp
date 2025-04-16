#include <bits/stdc++.h>

using namespace std;
using mat = vector<vector<int>>;
int diameter = 0;
mat tree;

int dfsHeight(int node, int parent, const mat &tree)
{
    int max1 = 0, max2 = 0;

    for (int child : tree[node])
    {
        if (child == parent)
            continue;

        int h = dfsHeight(child, node, tree);
        if (h > max1)
        {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2)
        {
            max2 = h;
        }
    }

    diameter = max(diameter, max1 + max2);
    return 1 + max1;
}

int computeDiametersDP(int n, const mat &tree)
{
    diameter = 0;
    dfsHeight(0, -1, tree);
    return diameter;
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

    cout << "Diameter of tree: " << computeDiametersDP(n, tree) << endl;
    return 0;
}