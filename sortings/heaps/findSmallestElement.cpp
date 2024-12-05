#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Partition function for Quickselect
int partition(vector<int> &arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int stroeIndex = left;

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[i], arr[stroeIndex]);
            stroeIndex++;
        }
    }

    swap(arr[stroeIndex], arr[right]);
    return stroeIndex;
}

// Quick select algorothm
void quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left < right)
    {
        int privotIndex = right;

        int pivotNewIndex = partition(arr, left, right, privotIndex);

        if (pivotNewIndex == k)
            return;

        else if (k < pivotNewIndex)
            quickSelect(arr, left, pivotNewIndex - 1, k);
        else
            quickSelect(arr, pivotNewIndex + 1, right, k);
    }
}

vector<int> kSmallestElements(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k >= n)
        return arr;

    quickSelect(arr, 0, n - 1, k);

    priority_queue<int> maxHeap;

    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }

    vector<int> result;
    while (!maxHeap.empty())
    {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return result;
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    vector<int> result = kSmallestElements(arr, k);
    cout << "The " << k << " smallest elements are: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}