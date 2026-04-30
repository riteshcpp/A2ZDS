/*
Maximum Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.
A binary array is an array that contains only 0s and 1s.
Example 1
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation:
The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s
Example 2
Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation:
No 1s are present in nums, thus we return 0
Now your turn!
Input: nums = [1, 0, 1, 1, 1, 0, 1, 1, 1]
Output: 3
Constraints
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int cnt = 0, max = 0;
    for (auto num : nums) {
        if (num == 1) {
            ++cnt;
            max = std::max(cnt, max);
        }
        else
            cnt = 0;
    }
    return max;
}

int main()
{
    std::vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0}; // Expected output: 3
    // std::vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0}; // Expected output: 0
    std::cout << findMaxConsecutiveOnes(nums) << std::endl;
    return 0;
}