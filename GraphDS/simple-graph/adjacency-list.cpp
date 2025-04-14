#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 5;
    // vector<int> adj[N];

    // adj[1].push_back(2);
    // adj[2].push_back(3);
    // adj[2].push_back(4);
    // adj[3].push_back(4);
    // adj[4].push_back(1);

    // for (int i = 0; i < N; ++i)
    // {
    //     cout << "Node: " << i << " ";
    //     for (int neighbor : adj[i])
    //     {
    //         cout << neighbor << " ";
    //     }
    //     cout << "\n";
    // }

    // return 0;
    // weighted graph representation

    vector<pair<int, int>> adjw[N];
    adjw[1].push_back({2, 5});
    adjw[2].push_back({3, 7});
    adjw[2].push_back({4, 6});
    adjw[3].push_back({4, 5});
    adjw[4].push_back({1, 2});

    for (int i = 0; i < N; ++i)
    {
        cout << "Node " << i << " -> ";
        for (auto edge : adjw[i])
        {
            cout << "(" << edge.first << ":, weight=" << edge.second << ")";
        }
        cout << "\n";
    }
}