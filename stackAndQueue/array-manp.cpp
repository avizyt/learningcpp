#include <bits/stdc++.h>

using namespace std;

using mat = vector<vector<int>>;

int main()
{
    stack<vector<int>> st;
    queue<vector<int>> q;

    mat m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < m.size(); i++)
    {
        q.push(m[i]);
    }

    vector<int> arr;

    while (!q.empty())
    {
        arr = q.front();
        int s = arr.size();
        for (int i = 0; i < s; ++i)
        {
            cout << arr.at(i) << " ";
        }

        q.pop();
    }
}