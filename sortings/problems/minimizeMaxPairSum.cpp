/**
 Take a list of 2n real numbers as input. Design an O(n log n) algorithm
that partitions the numbers into n pairs, with the property that the partition
minimizes the maximum sum of a pair. For example, say we are given the
numbers (1,3,5,9). The possible partitions are ((1,3),(5,9)), ((1,5),(3,9)), and
((1,9),(3,5)). The pair sums for these partitions are (4,14), (6,12), and (10,8).
Thus, the third partition has 10 as its maximum sum, which is the minimum
over the three partitions.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double minimizeMaxPairSum(std::vector<double> &nums)
{
    int n = nums.size() / 2;

    sort(nums.begin(), nums.end());

    double maxPairSum = 0;
    for (int i = 0; i < n; i++)
    {
        double pairSum = nums[i] + nums[2 * n - 1 - i];
        maxPairSum = max(maxPairSum, pairSum);
    }

    return maxPairSum;
}

int main()
{
    vector<double> nums = {1, 3, 5, 9};

    double result = minimizeMaxPairSum(nums);

    cout << "Minimum maximum pair sum: " << result << endl;

    return 0;
}
