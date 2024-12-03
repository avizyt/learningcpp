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
