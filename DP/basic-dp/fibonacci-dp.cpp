#include <bits/stdc++.h>

using namespace std;

int fibRecur(int n, vector<int> &dp)

/*
State: n

Transition: dp[n] = dp[n-1] + dp[n-2]

Base case: dp[0] = 0, dp[1] = 1

Time: O(n)

Pattern: Linear DP
*/

{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibRecur(n - 1, dp) + fibRecur(n - 2, dp);
}

int fibTablu(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 8;
    // vector<int> dp(n + 1, -1);
    // cout << fibRecur(n, dp);
    vector<int> dp;
    cout << fibTablu(n, dp);
    return 0;
}