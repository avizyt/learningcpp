#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<tuple<int, int, int>> edges;

    edges.push_back({1, 2, 5});
    edges.push_back({2, 3, 7});
    edges.push_back({2, 4, 6});
    edges.push_back({3, 4, 5});
    edges.push_back({4, 1, 2});

    for (const auto &edge : edges)
    {
        int from = get<0>(edge);
        int to = get<1>(edge);
        int weight = get<2>(edge);

        cout << "Edge: " << from << " -> " << to << "(w: " << weight << ")" << endl;
    }
    return 0;
}