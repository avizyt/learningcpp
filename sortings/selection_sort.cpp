#include <iostream>
#include <vector>
using namespace std;

// seletion sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    // loop through each element in the array
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap the found minimum element with the first element of the unsorted part
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// utility function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}