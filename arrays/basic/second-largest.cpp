#include <bits/stdc++.h>

using namespace std;

int findSecondLargest(vector<int> &arr, int n)
{

    if (n < 2)
    {
        return -1;
    }
    else
    {
        int first = INT_MIN;
        int second = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            if (arr.at(i) > first)
            {
                second = first;
                first = arr.at(i);
            }
            else if (arr.at(i) > second && arr.at(i) != first)
            {
                second = arr.at(i);
            }
        }
        return second;
    }
}

int main()
{
    // vector<int> arr = {3, 12, 4, 2, 7, 5, 10};
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    int n = arr.size();
    cout << findSecondLargest(arr, n);
}