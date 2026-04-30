/*
Sort an array of 0's 1's and 2's
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
The sorting must be done in-place, without making a copy of the original array.
Example 1
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation:
The nums array in sorted order has 2 zeroes, 2 ones and 1 two
Example 2
Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation:
The nums array in sorted order has 2 zeroes, 3 ones and zero twos
Now your turn!
Input: nums = [1, 1, 2, 2, 1]
Output:
Pick your answer
[1, 1, 1, 2, 2]
[1, 1, 2, 2, 2]
[2, 2, 1, 1, 1]
[1, 1, 2, 2, 1]
Constraints
1 <= nums.length <= 105
nums consists of 0, 1 and 2 only.
*/

#include <iostream>
#include <vector>

// Dutch National Flag Algorithm
// Time Complexity: O(n) Space Complexity: O(1)
void sortZeroOneTwo(std::vector<int>& nums) {
    int size = nums.size();
    for (int l = 0, m = 0, r = size - 1; m <= r;) {
        if (nums[m] == 0) {
            std::swap(nums[m++], nums[l++]);
        }
        else if (nums[m] == 1)
            ++m;
        else
            std::swap(nums[m], nums[r--]);
    }
}

int main()
{
    // std::vector<int> nums = {1, 0, 2, 1, 0}; // Output: [0, 0, 1, 1, 2]
    // std::vector<int> nums = {0, 0, 1, 1, 1}; // Output: [0, 0, 1, 1, 1]
    std::vector<int> nums = {1, 1, 2, 2, 1}; // Output: [1, 1, 1, 2, 2]
    sortZeroOneTwo(nums);
    for (auto num : nums) std::cout << num << " ";

    return 0;
}