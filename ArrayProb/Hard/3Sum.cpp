/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
Example 4:
Input: nums = [2, -2, 0, 3, -3, 5]
Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]
Explanation:
nums[1] + nums[2] + nums[0] = 0
nums[4] + nums[1] + nums[5] = 0
nums[4] + nums[2] + nums[3] = 0
Example 5:
Input: nums = [2, -1, -1, 3, -1]
Output: [[-1, -1, 2]]
Explanation:
nums[1] + nums[2] + nums[0] = 0
Note that we have used two -1s as they are separate elements with different indexes
But we have not used the -1 at index 4 as that would create a duplicate triplet
Example 6:
Input: nums = [8, -6, 5, 4]
Output: []
Explanation: No three numbers sum up to zero.
Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

// Tutorial: https://www.youtube.com/watch?v=DhFh8Kw7ymk

#include <iostream>
#include <vector>
#include <algorithm>

// Logic: Sort the array to avoid duplicates and use two pointers approach for each value of i in the array. For each i, set two pointers j and k, where j starts from i+1 and k starts from the end of the array. Move the pointers based on the sum of nums[i], nums[j], and nums[k] to find triplets that sum to zero. In place of zero we can check for any target sum.
// Time Complexity: O(n^2) Space Complexity: O(1)
// LeetCode Link: https://leetcode.com/problems/3sum/description/
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    std::ranges::sort(nums);
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) // to avoid duplicates, move i to next different element
            continue;
        int j = i + 1, k = size - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.emplace_back(std::initializer_list<int>{nums[i], nums[j], nums[k]});
                while (j < k && nums[++j] == nums[j - 1]); // to avoid duplicates, move j to next different element
                while (j < k && nums[--k] == nums[k + 1]); // to avoid duplicates, move k to previous different element
            } else if (sum < 0) {
                ++j;
            } else {
                --k;
            }
        }
    }
    return result;
}

// Example usage or driver code
int main()
{
    // Example 1
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result1 = threeSum(nums1);
    std::cout << "Example 1: ";
    for (const auto &triplet : result1)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 2
    std::vector<int> nums2 = {0, 1, 1};
    std::vector<std::vector<int>> result2 = threeSum(nums2);
    std::cout << "Example 2: ";
    for (const auto &triplet : result2)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 3
    std::vector<int> nums3 = {0, 0, 0};
    std::vector<std::vector<int>> result3 = threeSum(nums3);
    std::cout << "Example 3: ";
    for (const auto &triplet : result3)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 4
    std::vector<int> nums4 = {2, -2, 0, 3, -3, 5};
    std::vector<std::vector<int>> result4 = threeSum(nums4);
    std::cout << "Example 4: ";
    for (const auto &triplet : result4)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 5
    std::vector<int> nums5 = {2, -1, -1, 3, -1};
    std::vector<std::vector<int>> result5 = threeSum(nums5);
    std::cout << "Example 5: ";
    for (const auto &triplet : result5)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 6
    std::vector<int> nums6 = {8, -6, 5, 4};
    std::vector<std::vector<int>> result6 = threeSum(nums6);
    std::cout << "Example 6: ";
    for (const auto &triplet : result6)
    {
        std::cout << "[";
        for (int num : triplet)
            std::cout << num << " ";
        std::cout << "] ";
    }
    std::cout << "\n";

    return 0;
}