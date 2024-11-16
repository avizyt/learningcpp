#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {

        // to avoid overflow
        int mid = left + (right - left) / 2;

        // check if the target is at mid
        if (arr[mid] == target)
        {
            return mid;
        }

        // If target is greater, ignore the left half
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Sorted array
    int target = 7;

    int result = binarySearch(arr, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}