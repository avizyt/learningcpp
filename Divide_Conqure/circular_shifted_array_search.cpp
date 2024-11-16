
/*Question 5.1 (Algorithm Design Manual(ADM))

Suppose you are given a sorted array A of size n that has been circularly
shifted k positions to the right. For example, [35, 42, 5, 15, 27, 29] is a sorted
array that has been circularly shifted k = 2 positions, while [27, 29, 35, 42, 5, 15]
has been shifted k = 4 positions

1. Suppose you know what k is. Give an O(1) algorithm to find the largest
number in A.
2. Suppose you do not know what k is. Give an O(lg n) algorithm to find the
largest number in A. For partial credit, you may give an O(n) algorithm

*/

#include <iostream>
#include <vector>

using namespace std;

// Knowing k (O(1) algorithm)

int findLargestWithK(const vector<int> &A, int k)
{
    int n = A.size();
    return A[(k - 1) % n];
}

// Not knowing k (o(log n)) algorithm
int findLargestWithoutK(const vector<int> &A)
{
    int n = A.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] > A[(mid + 1) % n])
        {
            return A[mid];
        }

        if (A[mid] < A[low])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// O(n) Algorithm

int findLargestLinear(const vector<int> &A)
{
    int largest = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > largest)
        {
            largest = A[i];
        }
    }
    return largest;
}

int main()
{
    // Test case: Circularly shifted sorted array
    vector<int> A = {35, 42, 5, 15, 27, 29};
    int k = 2;

    // Case 1: Finding largest with known k
    cout << "Largest element with known k: " << findLargestWithK(A, k) << endl;

    // Case 2: Finding largest with unknown k using O(log n)
    cout << "Largest element with unknown k (O(log n)): " << findLargestWithoutK(A) << endl;

    // Case 3: Finding largest with unknown k using O(n)
    cout << "Largest element with unknown k (O(n)): " << findLargestLinear(A) << endl;

    return 0;
}