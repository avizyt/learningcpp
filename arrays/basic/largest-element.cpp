#include <bits/stdc++.h>

using namespace std;

int findLargest(vector<int> &arr)
{
    int n = arr.size() - 1;
    int largest = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr.at(i) > largest)
        {
            largest = arr.at(i);
        }
    }
    return largest;
}

int findLargest2(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return (arr[arr.size() - 1]);
}

int main()
{
    vector<int> arr = {2, 5, 1, 3, 0};
    // cout << "largest: " << findLargest(arr) << endl;
    cout << "largest: " << findLargest2(arr) << endl;
}