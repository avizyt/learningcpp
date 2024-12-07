/*Question 4.19 (ADM)

You wish to store a set of n numbers in either a max-heap or a sorted array.
For each application below, state which data structure is better, or if it does not
matter. Explain your answers.
(a) Find the maximum element quickly.
(b) Delete an element quickly.
(c) Form the structure quickly.
(d) Find the minimum element quickly.

Explanation: sortings\heaps\maxHeap_prblem_solution.md
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // For max-heap (priority_queue)

using namespace std;

// max heap from given array
void createMaxHeap(vector<int> &arr)
{
    make_heap(arr.begin(), arr.end());
}

void createSortedArray(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

int findMaxInHeap(const vector<int> &heap)
{
    return heap.front();
}

int findMaxInSortedArray(vector<int> &arr)
{
    return arr.back();
}

int findMinInSortedArray(vector<int> &arr)
{
    return arr.front();
}

int findMinInHeap(const vector<int> &heap)
{
    int minVal = INT_MAX;
    for (int val : heap)
    {
        minVal = min(minVal, val);
    }
    return minVal;
}

void deleteFromSortedArray(vector<int> &arr, int element)
{
    // use binary search to find the element (O(log n))
    auto it = lower_bound(arr.begin(), arr.end(), element);
    if (it != arr.end() && *it == element)
    {
        arr.erase(it);
    }
    else
    {
        cout << "Element not found!" << endl;
    }
}

void deleteFromMaxHeap(vector<int> &heap, int element)
{
    auto it = find(heap.begin(), heap.end(), element);
    if (it != heap.end())
    {
        *it = heap.back();
        heap.pop_back();
        make_heap(heap.begin(), heap.end());
    }
    else
    {
        cout << "Element not found!" << endl;
    }
}

int main()
{
    vector<int> nums = {10, 20, 5, 8, 2, 18};
    vector<int> heap = nums;        // Copy array for heap operations
    vector<int> sortedArray = nums; // Copy array for sorted array operations

    // Build max-heap
    createMaxHeap(heap);

    // Build sorted array
    createSortedArray(sortedArray);

    cout << "Max-Heap: ";
    for (int x : heap)
        cout << x << " ";
    cout << endl;

    cout << "Sorted Array: ";
    for (int x : sortedArray)
        cout << x << " ";
    cout << endl;

    // Find the maximum
    cout << "Max in Heap: " << findMaxInHeap(heap) << endl;
    cout << "Max in Sorted Array: " << findMaxInSortedArray(sortedArray) << endl;

    // Find the minimum
    cout << "Min in Heap: " << findMinInHeap(heap) << endl;
    cout << "Min in Sorted Array: " << findMinInSortedArray(sortedArray) << endl;

    // Delete an element
    cout << "Deleting 10 from Sorted Array..." << endl;
    deleteFromSortedArray(sortedArray, 10);
    cout << "Sorted Array after deletion: ";
    for (int x : sortedArray)
        cout << x << " ";
    cout << endl;

    cout << "Deleting 10 from Heap..." << endl;
    deleteFromMaxHeap(heap, 10);
    cout << "Heap after deletion: ";
    for (int x : heap)
        cout << x << " ";
    cout << endl;

    return 0;
}