#include <iostream>
#include <vector>

using namespace std;

// heapify as subtree rooted at node i
void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check if the left and right child exist and is geater than the root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // if the largest is not the root, swap and continue heapifying
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i > 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    // extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
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

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}