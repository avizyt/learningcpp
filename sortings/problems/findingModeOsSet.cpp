/*Question 4.5 (ADM)
The mode of a bag of numbers is the number that occurs most frequently in
the set. The set {4, 6, 2, 4, 3, 1} has a mode of 4. Give an efficient and correct
algorithm to compute the mode of a bag of n numbers.
*/

#include <iostream>
#include <vector>
#include <unordered_map> // For hash table

int findMode(const std::vector<int> &nums)
{
    std::unordered_map<int, int> frequency; // Hash table to store frequencies
    int mode = nums[0];
    int maxFreq = 0;

    // Count frequencies and track the mode
    for (int num : nums)
    {
        frequency[num]++;
        if (frequency[num] > maxFreq)
        {
            maxFreq = frequency[num];
            mode = num;
        }
    }

    return mode;
}

int main()
{
    // Example input: Bag of numbers
    std::vector<int> nums = {4, 6, 2, 4, 3, 1};

    // Find the mode
    int mode = findMode(nums);

    // Output the result
    std::cout << "Mode: " << mode << std::endl;

    return 0;
}
