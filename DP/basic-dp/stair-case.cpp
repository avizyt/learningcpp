#include <bits/stdc++.h>

using namespace std;

int totalWayRec(int numberOfStairs)
{
    vector<int> dp(numberOfStairs + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= numberOfStairs; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[numberOfStairs];
}

int countAllTheWayToTop(int numberOfStairs)
{
    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= numberOfStairs; ++i)
    {
        int curr_idx = prev2 + prev;
        prev2 = prev;
        prev = curr_idx;
    }
    return prev;
}

int main()
{
    int n = 5;
    cout << countAllTheWayToTop(n) << endl;
    cout << totalWayRec(n) << endl;
}