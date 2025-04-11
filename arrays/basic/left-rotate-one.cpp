#include <bits/stdc++.h>

using namespace std;

vector<int> leftRotate1(vector<int> &arr)
{
    int n = arr.size();

    vector<int> rot1arr = {};

    int first = arr.at(0);
    if (n == 1)
    {
        rot1arr.emplace_back(arr.at(0));
        return rot1arr;
    }
    for (int i = 1; i < n; ++i)
    {
        rot1arr.emplace_back(arr.at(i));
    }
    rot1arr.emplace_back(first);
    return rot1arr;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr = {1};
    vector<int> newarr = leftRotate1(arr);
    for (int item : newarr)
    {
        cout << item << " " << endl;
    }
}