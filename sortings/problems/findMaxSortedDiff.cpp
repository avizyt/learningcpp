#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxDifference(vector<int> &arr)
{
    int diff = 0;
    int n = arr.size() - 1;

    if (n != 0 && arr[0] < arr[1])
    {
        diff = arr[1] - arr[0];
    }
    else
    {
        diff = arr[n - 1] - arr[n];
    }
    return diff;
}

int main()
{
    vector<int> arr1 = {3, 4, 6, 7, 9};
    vector<int> arr2 = {9, 8, 7, 5, 3};
    cout << findMaxDifference(arr1) << endl;
    cout << findMaxDifference(arr2) << endl;
}