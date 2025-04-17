#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr_after;
    vector<int> arr_before;

    int x = 1;
    for (int i = 0; i <= 5; ++i)
    {
        arr_before.emplace_back(x);
        cout << x++ << " ";
        arr_after.emplace_back(x);
        cout << ++x << " ";
    }

    cout << endl;

    for (int item : arr_before)
    {
        cout << item << " ";
    }

    cout << endl;

    for (int item : arr_after)
    {
        cout << item << " ";
    }
}