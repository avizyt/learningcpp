/* Question 4.6 (ADM)
 Given two sets S1 and S2 (each of size n), and a number x, describe an
O(n log n) algorithm for finding whether there exists a pair of elements, one
from S1 and one from S2, that add up to x. (For partial credit, give a Θ(n2)
algorithm for this problem.)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool findAddPair(int num, vector<int> &arr1, vector<int> &arr2)
{

    int residue = 0;
    for (int x : arr1)
    {
        residue = num - x;
        for (int y : arr2)
        {
            if (y == residue)
            {
                return true;
            }
        }
    }
    return false;
}

bool findAddPairOptimized(int num, vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> hashSet(arr2.begin(), arr2.end());

    for (int x : arr1)
    {
        int residue = num - x;
        if (hashSet.find(residue) != hashSet.end())
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int number = 10;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 6, 1, 8, 4, 7};
    cout << findAddPair(number, arr1, arr2) << endl;
    cout << findAddPairOptimized(number, arr1, arr2) << endl;
}
