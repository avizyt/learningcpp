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

bool findAddPairOptimized(int num, std::vector<int> &arr1, std::vector<int> &arr2)
{
    std::unordered_set<int> hashSet(arr2.begin(), arr2.end());

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
    vector<int> arr2 = {2, 6, 1, 8, 4};
    cout << findAddPair(number, arr1, arr2) << endl;
    cout << findAddPairOptimized(number, arr1, arr2) << endl;
}
