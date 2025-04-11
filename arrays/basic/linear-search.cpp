#include <bits/stdc++.h>

using namespace std;

int linearSearch(vector<int> &arr, int num)
{
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        if (arr.at(i) == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {5, 4, 3, 2, 1};

    cout << linearSearch(arr, 3) << endl;
    cout << linearSearch(arr2, 1) << endl;
}