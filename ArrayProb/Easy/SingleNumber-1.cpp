/*
Single Number - I
Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.
Example 1
Input : nums = [1, 2, 2, 4, 3, 1, 4]
Output : 3
Explanation : The integer 3 has appeared only once.
Example 2
Input : nums = [5]
Output : 5
Explanation : The integer 5 has appeared only once.
Now your turn!
Input : nums = [1, 3, 10, 3, 5, 1, 5] // Expected Output : 10
Output:
Pick your answer
1
3
5
10
Constraints
1 <= n <= 105
-3*105 <= nums[i] <= 3*105
*/

#include <iostream>
#include <vector>

// XOR approach
int singleNumber(std::vector<int> &nums)
{
    int res = 0;
    for (auto num : nums)
        res ^= num;
    return res;
}

// Single pass without XOR and extra space
// Assumes that the input array is sorted
int singleNonDuplicate(std::vector<int> &nums)  
{
    int size = nums.size();
    int i = 0;
    for (; i + 1 < size; i += 2)
    {
        if (nums[i] != nums[i + 1])
            break;
    }
    return nums[i];
}

int main()
{
    // std::vector<int> nums = {1, 2, 2, 4, 3, 1, 4}; // Expected output: 3
    // std::vector<int> nums = {1}; // Expected output: 1
    std::vector<int> nums = {4, 1, 2, 1, 2}; // Expected output: 4
    std::cout << singleNumber(nums) << std::endl;
    return 0;
}