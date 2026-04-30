/*
2395. Find Subarrays With Equal Sum
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
Return true if these subarrays exist, and false otherwise.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:
Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:
Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
Constraints:
2 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_set>

// Logic: Use a hash set to store sums of subarrays of length 2. If a sum already exists in the set, return true. If we finish checking all subarrays without finding duplicates, return false.
// LeetCode Link: https://leetcode.com/problems/find-subarrays-with-equal-sums/description/
// Time Complexity: O(n) as we traverse the array once.
// Space Complexity: O(n) for storing sums in the hash set.
bool findSubarrays(std::vector<int> &nums)
{
    std::unordered_set<int> sum;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int s = nums[i] + nums[i + 1];
        if (sum.contains(s))
            return true;
        sum.insert(s);
    }
    return false;
}

int main()
{
    // Example 1
    std::vector<int> nums1 = {4, 2, 4}; // Expected output: true
    std::cout << "Example 1: " << (findSubarrays(nums1) ? "true" : "false") << std::endl;

    // Example 2
    std::vector<int> nums2 = {1, 2, 3, 4, 5}; // Expected output: false
    std::cout << "Example 2: " << (findSubarrays(nums2) ? "true" : "false") << std::endl;

    // Example 3
    std::vector<int> nums3 = {0, 0, 0}; // Expected output: true
    std::cout << "Example 3: " << (findSubarrays(nums3) ? "true" : "false") << std::endl;

    return 0;
}