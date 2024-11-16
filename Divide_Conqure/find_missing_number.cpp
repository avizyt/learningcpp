/*Question 5.2 (ADM)
A sorted array of size n contains distinct integers between 1 and n + 1, with
one element missing. Give an O(log n) algorithm to find the missing integer,
without using any extra space.
*/
#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> &A)
{
    int n = A.size();
    if (n == 0)
    {
        cout << "Empty Array!" << endl;
    }
    else
    {

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (A[mid] > mid + 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low + 1;
    }
}

int main()
{
    vector<int> l1 = {1, 2, 4, 5, 6, 7, 8, 9, 10}; // Missing number is 4
    vector<int> l2 = {};
    vector<int> l3 = {2};
    vector<int> l4 = {1, 2, 3, 4, 5};

    vector<vector<int>> list = {l1, l2, l3, l4};

    // for (int i = 0; i <= list.size() - 1; i++)
    // {
    //     cout << "The missing number is: " << findMissingNumber(list[i]) << endl;
    // }
    for (vector<int> A : list)
    {
        cout << "The missing number is: " << findMissingNumber(A) << endl;
    }
    return 0;
}