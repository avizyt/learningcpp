#include <iostream>
#include <vector>

using namespace std;

// merge function to merge two halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of the left sub-array
    int n2 = right - mid;    // size of the right sub-array

    // create temporary arrays
    vector<int> L(n1), R(n2);

    // copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy any remaining element of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy any remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// mearge sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // recursive divide the array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // merge the sorted halves
        merge(arr, left, mid, right);
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
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
