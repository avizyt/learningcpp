#include <bits/stdc++.h>

using namespace std;

int knapsack(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (i == 0)
        return wt[0] <= W ? val[0] : 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    int notTake = knapsack(i - 1, W, wt, val, dp);
    int take = (wt[i] <= W) ? val[i] + knapsack(i - 1, W - wt[i], wt, val, dp) : 0;

    return dp[i][W] = max(take, notTake);
}

int knapsackTablu(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: fill first row
    for (int w = wt[0]; w <= W; ++w)
    {
        dp[0][w] = val[0];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            int notTake = dp[i - 1][w];
            int take = (wt[i] <= w) ? val[i] + dp[i - 1][w - wt[i]] : 0;
            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    // vector<int> wt = {2, 3, 4, 5};
    // vector<int> val = {3, 4, 5, 6};
    // int W = 5;
    // int n = wt.size();
    // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // cout << "Max knapsack value = " << knapsack(n - 1, W, wt, val, dp) << endl;

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    cout << "Max value (Tabulation): " << knapsackTablu(wt, val, W) << endl;
}