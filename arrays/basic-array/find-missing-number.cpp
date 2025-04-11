#include <bits/stdc++.h>

using namespace std;

int findMissingNumberIterative(int n, vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int missingNumber = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] + 1 != arr[i + 1])
        {
            missingNumber = arr[i] + 1;
        }
    }
    return missingNumber;
}

int findMissingNumberOptimal(int n, vector<int> &arr)
{
    // use 1LL to avoid overflow
    long long totalSum = (1LL * n * (n + 1)) / 2;
    long long actualSum = 0;
    for (int item : arr)
    {
        actualSum += item;
    }
    return totalSum - actualSum;
}

int findMissingNumberBitwise(int n, vector<int> &arr)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 1; i <= n; ++i)
        xor1 ^= i;
    for (int x : arr)
        xor2 ^= x;

    return xor1 ^ xor2;
}

int main()
{
    vector<int> arr = {2, 3, 1, 5};
    int n = arr.size();
    cout << "Missing Number: " << findMissingNumberIterative(n, arr) << "\n";
    cout << "Missing Number: " << findMissingNumberOptimal(n + 1, arr) << "\n";
    cout << "Missing Number: " << findMissingNumberBitwise(n + 1, arr) << "\n";
}