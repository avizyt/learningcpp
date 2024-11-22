#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int RUN = 32;

// Perform insertion sort on a subarray
void insertionSort(vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge two sorted subarrays
void merge(vector<int> &arr, int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;

    // Create temporary arrays
    vector<int> leftArr(len1);
    vector<int> rightArr(len2);

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the main array
    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Perform Timsort on the array
void timSort(vector<int> &arr, int n)
{
    // Sort individual subarrays of size RUN using insertion sort
    for (int i = 0; i < n; i += RUN)
    {
        insertionSort(arr, i, min(i + RUN - 1, n - 1));
    }

    // Start merging from size RUN
    for (int size = RUN; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            // Merge subarrays if mid < right
            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Utility function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Main function
int main()
{
    vector<int> arr = {5, 21, 7, 23, 19, 10, 15, 30, 3, 2};

    cout << "Original array: ";
    printArray(arr);

    timSort(arr, arr.size());

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
