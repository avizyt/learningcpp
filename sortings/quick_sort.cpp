#include <iostream>
#include <vector>

using namespace std;

// partition function to place the pivot element at its correct position
int partition(vector<int> &arr, int low, int high)
{
    // choosing the last element as the pivot
    int pivot = arr[high];

    // smaller element is the index
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        // if the current element is the smaller or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++;
            // swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // swap the pivot element with the element at i+1
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);

        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}