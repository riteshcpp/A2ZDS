/*
18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
Example 3:
Input: nums = [1, -2, 3, 5, 7, 9], target = 7
Output: [[-2, 1, 3, 5]]
Explanation:
nums[1] + nums[0] + nums[2] + nums[3] = 7
Example 4:
Input: nums = [7, -7, 1, 2, 14, 3], target = 9
Output: []
Explanation:
No quadruplets are present which add upto 9
Example 5:
Input: nums = [1, 1, 3, 4, -3], target = 5
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <vector>
#include <algorithm>
#include <iostream>

// Logic: Sort the array to avoid duplicates and use two pointers approach for each pair of i and j in the array
// Time Complexity: O(n^3) Space Complexity: O(1)
// LeetCode Link: https://leetcode.com/problems/4sum/description/
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    int size = nums.size();
    std::vector<std::vector<int>> result;
    std::ranges::sort(nums);
    for (int i = 0; i < size; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < size; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int l = j + 1, r = size - 1;
            while (l < r) {
                // adding long long and separately to avoid integer overflow
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[l];
                sum += nums[r];
                if (sum == target) {
                    // Here we use emplace_back with initializer_list to directly construct the inner vector, with push_back we can directly create a vector using {}, no need to explictly use of initializer_list.
                    result.emplace_back(std::initializer_list<int>{nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[++l] == nums[l - 1]){}
                    while (l < r && nums[--r] == nums[r + 1]){}
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
    }
    return result;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    auto result1 = fourSum(nums1, 0);
    std::cout << "Example 1: ";
    for (auto& quad : result1) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 2
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    auto result2 = fourSum(nums2, 8);
    std::cout << "Example 2: ";
    for (auto& quad : result2) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 3
    std::vector<int> nums3 = {1, -2, 3, 5, 7, 9};
    auto result3 = fourSum(nums3, 7);
    std::cout << "Example 3: ";
    for (auto& quad : result3) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 4
    std::vector<int> nums4 = {7, -7, 1, 2, 14, 3};
    auto result4 = fourSum(nums4, 9);
    std::cout << "Example 4: ";
    for (auto& quad : result4) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    // Example 5
    std::vector<int> nums5 = {1, 1, 3, 4, -3};
    auto result5 = fourSum(nums5, 5);
    std::cout << "Example 5: ";
    for (auto& quad : result5) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n";

    return 0;
}