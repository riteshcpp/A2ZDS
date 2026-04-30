/*
Find missing number
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
Example 1
Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation:
nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]
Example 2
Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation:
nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]
Now your turn!
Input: nums = [1, 3, 6, 4, 2, 5]
Output:
Pick your answer
6
7
0
8
Constraints
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
*/
#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int xor1 = 0, xor2 = 0;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ nums[i];
    }
    return xor1 ^ xor2;
}

int main()
{
    // std::vector<int> nums = {0, 2, 3, 1, 4};
    std::vector<int> nums = {0, 1, 2, 4, 5, 6};
    std::cout << missingNumber(nums) << std::endl;
    return 0;
}