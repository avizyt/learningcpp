/*Question 6.2 (ADM)
Suppose we flip n coins each of known bias, such that pi is the probability of
the ith coin being a head. Present an efficient algorithm to determine the exact
probability of getting exactly k heads given p1,...,pn ∈ [0, 1].
*/

#include <iostream>
#include <vector>

using namespace std;

// function to calculate the probability of exatly k heads
double probsOfKHeads(vector<double> &p, int k)
{
    int n = p.size();

    // DP table where P[i][j] represents the prob of getting j heads with the first i coins
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));

    // base case: 0 heads with 0 coind is 1
    dp[0][0] = 1.0;

    // fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            // probability of not picking heads from the ith coin
            dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);

            // probability of picking heads from the ith coin
            if (j > 0)
            {
                dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    vector<double> probabilities = {0.5, 0.6, 0.7}; // Biases of coins
    int k = 2;                                      // Target number of heads

    double result = probsOfKHeads(probabilities, k);

    cout << "The probability of getting exactly " << k << " heads is: " << result << endl;

    return 0;
}