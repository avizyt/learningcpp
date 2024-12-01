#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxDifference(vector<int> &arr)
{
    int max = INT_MIN;
    int min = INT_MAX;
    if (arr.size() == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i <= arr.size() - 1; i++)
        {
            if (max < arr[i] && min < arr[i])
            {
                max = arr[i];
            }
            else
            {
                if (min > arr[i])
                {
                    min = arr[i];
                }
            }
        }
    }
    int maxDiff = max - min;
    return maxDiff;
}

int findMaxDiff(vector<int> &arr)
{
    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    for (int x : arr)
    {
        if (x > maxVal)
            maxVal = x;
        if (x < minVal)
            minVal = x;
    }

    return (maxVal - minVal);
}

int main()
{
    // vector<int> s = {2, 1};
    std::vector<int> s = {6, 13, 19, 3, 8};
    cout << "Max Difference: " << findMaxDifference(s) << endl;
    cout << "Max Difference: " << findMaxDiff(s) << endl;
}