/* Question 5.5 (ADM)
] Suppose that you are given a sorted sequence of distinct integers [a1, a2,...,an].
Give an O(lg n) algorithm to determine whether there exists an index i such that
ai = i. For example, in [−10, −3, 3, 5, 7], a3 = 3. In [2, 3, 4, 5, 6, 7], there is no
such i.
*/

#include <iostream>
#include <vector>

using namespace std;

int findDistintNumber(const vector<int> &A)
{
    int n = A.size();
    // if (n == 0)
    // {
    //     return -1;
    // }
    // else
    // {
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == mid)
        {
            return mid;
        }
        else if (A[mid] > mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
    // }
}

int main()
{
    vector<int> A = {-10, -3, 3, 5, 7};

    cout << "Distinct Integers: " << findDistintNumber(A) << endl;
}