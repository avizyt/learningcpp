#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int maxSubArraySumOne(vector<int> &arr)
{
    int best = 0;
    int n = arr.size() - 1;
    for (int i = 0; i < n; i++)
    {
        for (int b = i; b < n; b++)
        {
            int sum = 0;
            for (int k = i; k <= b; k++)
            {
                sum += arr[k];
            }
            best = max(best, sum);
        }
    }
    return best;
}

int maxSubArraySumTwo(vector<int> &arr)
{
    int best = 0;
    int n = arr.size() - 1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            best = max(best, sum);
        }
    }
    return best;
}

int maxSubArraySumOptm(vector<int> &arr)
{
    int best = 0, sum = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }

    return best;
}

int main()
{
    vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};

    auto start = high_resolution_clock::now();
    // cout << "Max sub array sum: " << maxSubArraySumOne(arr) << "\n";
    // cout << "Max sub array sum: " << maxSubArraySumTwo(arr) << "\n";
    cout << "Max sub array sum: " << maxSubArraySumOptm(arr) << "\n";
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<microseconds>(end - start);
    cout << "Total Time taken: " << time_taken;
}
