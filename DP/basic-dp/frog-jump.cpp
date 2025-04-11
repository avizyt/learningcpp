#include <bits/stdc++.h>

using namespace std;

int frogJumpRec(int i, const vector<int> &height)
{
    if (i == 0)
    {
        return 0;
    }

    int jumpOne = frogJumpRec(i - 1, height) + abs(height[i] - height[i - 1]);

    int jumpTwo = INT_MAX;

    if (i > i)
    {
        jumpTwo = frogJumpRec(i - 2, height) + abs(height[i] - height[i - 2]);
    }

    return min(jumpOne, jumpTwo);
}

int frogJumpMemo(int i, const std::vector<int> &height, std::vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int jumpOne = frogJumpMemo(i - 1, height, dp) + std::abs(height[i] - height[i - 1]);

    int jumpTwo = INT_MAX;
    if (i > 1)
    {
        jumpTwo = frogJumpMemo(i - 2, height, dp) + std::abs(height[i] - height[i - 2]);
    }

    dp[i] = std::min(jumpOne, jumpTwo);
    return dp[i];
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int idx = height.size();
    vector<int> dp(idx, -1);
    // cout << frogJumpRec(idx - 1, height);
    cout << frogJumpMemo(idx - 1, height, dp);
}