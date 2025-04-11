#include <iostream>
#include <vector>

using namespace std;

// bubble sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size() - 1;

    int numberOfInversion = 0;
    for (int i = 0; i < n; i++)
    {
        // flag to optimize if no swaps occur
        bool swapped = false;

        // compare adjacent elements
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap if element are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
                numberOfInversion += 1;
            }
        }

        // if no element were swapped, the array is already sorted
        if (!swapped)
            break;
    }
    cout << "Number of inversion: " << numberOfInversion << "\n";
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

    bubbleSort(arr);
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}