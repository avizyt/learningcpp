#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &arr)
{
    int n = arr.size() - 1;
    for (int i = 0; i < n; ++i)
    {
        int f = arr.at(i);
        int s = arr.at(i + 1);
        if (f > s)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << isSorted(arr);
}