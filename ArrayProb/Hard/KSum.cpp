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

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// This is K-Sum generalized solution works for 2-Sum, 3-Sum, 4-Sum and so on but here just implementing for 4-Sum
// Logic: Use recursion to reduce K-Sum to (K-1)-Sum until we reach 2-Sum where we can use two pointers approach
// Time Complexity: O(n^(k-1)) Space Complexity: O(k)
// LeetCode Link: https://leetcode.com/problems/4sum/description/
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    int size = nums.size();
    std::vector<std::vector<int>> result;
    std::vector<int> quad;
    std::ranges::sort(nums);

    // std::function for recursive kSum, as lambda cannot refer to itself directly, use & to capture by reference
    std::function<void(int, int, long long)> kSum;
    kSum = [&] (int k, int start, long long target) {
        if (k != 2) {
            for (int i = start; i <= size - k; ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                quad.push_back(nums[i]);
                kSum(k - 1, i + 1, target - nums[i]);
                quad.pop_back();
            }
            return;
        }
        int l = start, r = size - 1;
        while(l < r) {
            long long sum = (long long)nums[l] + nums[r];
            if (sum == target) {
                result.push_back(quad);
                result.back().push_back(nums[l]);
                result.back().push_back(nums[r]);
                while(l < r && nums[++l] == nums[l - 1]);
                while(l < r && nums[--r] == nums[r + 1]);
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
    };
    
    kSum(4, 0, target);
    return result;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    auto result1 = fourSum(nums1, target1);
    std::cout << "Example 1: ";
    for (const auto& quad : result1) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n\n";

    // Example 2
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    auto result2 = fourSum(nums2, target2);
    std::cout << "Example 2: ";
    for (const auto& quad : result2) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n\n";

    // Example 3
    std::vector<int> nums3 = {1, -2, 3, 5, 7, 9};
    int target3 = 7;
    auto result3 = fourSum(nums3, target3);
    std::cout << "Example 3: ";
    for (const auto& quad : result3) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n\n";

    // Example 4
    std::vector<int> nums4 = {7, -7, 1, 2, 14, 3};
    int target4 = 9;
    auto result4 = fourSum(nums4, target4);
    std::cout << "Example 4: ";
    for (const auto& quad : result4) {
        std::cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << "\n\n";

    // Example 5
    std::vector<int> nums5 = {1, 1, 3, 4, -3};
    int target5 = 5;
    auto result5 = fourSum(nums5, target5);
    std::cout << "Example 5: ";
    for (const auto& quad : result5) {
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