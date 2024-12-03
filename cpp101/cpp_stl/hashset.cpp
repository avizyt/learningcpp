#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    vector<int> arr = {2, 1, 4, 2, 5, 6, 7};
    unordered_set<int> hashSet(arr.begin(), arr.end());
    int num = 5;
    for (int item : hashSet)
    {
        // if (hashSet.find(num) != hashSet.end())
        // {
        //     cout << item << endl;
        // }
        cout << item << endl;
    }
}