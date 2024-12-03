#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, int> countDict(unordered_set<int> s)
{
    unordered_map<int, int> dict;
    for (int num : s)
    {
        dict[num]++;
    }
    return dict;
}

int findModeOfSet(unordered_set<int> s)
{
    unordered_map<int, int> umap = countDict(s);
    int maxValue = INT_MIN;
    int mode;
    for (const auto &pair : umap)
    {
        if (pair.second > maxValue)
        {
            maxValue = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

int main()
{
    unordered_set<int> s = {4, 6, 2, 4, 3, 1};
    return findModeOfSet(s);
}