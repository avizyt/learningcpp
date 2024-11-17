/* Question 5.4 (ADM)
You are given a unimodal array of n distinct elements, meaning that its
entries are in increasing order up until its maximum element, after which its
elements are in decreasing order. Give an algorithm to compute the maximum
element of a unimodal array that runs in O(log n) time

*/

#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> A)
{
    int n = A.size();

    if (n == 0)
    {
        return -1;
    }
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] < A[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return A[low];
}

int main()
{
    // vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5};
    vector<int> A = {2, 5, 7, 12, 14, 16, 18, 25, 23, 15, 13, 11, 9, 6};

    cout << "Maxium number in the array: " << findMax(A) << endl;
}