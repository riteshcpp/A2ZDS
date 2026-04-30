/*
31. Next Permutation (LeetCode Medium)
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
#include <algorithm>

// Version 1: Manual Implementation
// Approach: Find the rightmost position where nums[i] < nums[i+1]
// Then find the smallest element to the right that is greater than nums[i]
// Swap them and reverse the suffix after position i
void nextPermutation_Manual(std::vector<int>& nums) {
    int idx = -1;
    int size = nums.size();
    
    // Find the first decreasing element from the end, to identify the pivot
    for (int i = size - 2; i >= 0; --i) {
        if (nums[i] < nums[i+1]) {
            idx = i;
            break;
        }
    }
    // If no such point is found, reverse the entire array to get the smallest permutation
    if (idx == -1) {
        std::reverse(nums.begin(), nums.end());
        return;
    }
    // Find the rightmost element that is greater than nums[idx] and swap
    for (int i = size - 1; i > idx; --i) {
        if (nums[i] > nums[idx]) {
            std::swap(nums[i], nums[idx]);
            break;
        }
    }
    // Reverse the suffix starting right after the pivot index to get them in ascending order
    std::reverse(nums.begin() + idx + 1, nums.end());
}

// Version 2: Using STL Built-in Function
// Approach: Directly use std::next_permutation which handles all logic internally
void nextPermutation_STL(std::vector<int>& nums) {
    std::next_permutation(nums.begin(), nums.end());
}

int main() {
    // Test Case 1: [1,2,3] -> [1,3,2]
    std::vector<int> nums1 = {1, 2, 3};
    std::cout << "Input: [1,2,3]\n";
    nextPermutation_Manual(nums1);
    std::cout << "Output (Manual): ";
    for (int num : nums1) std::cout << num << " ";
    std::cout << "\n\n";

    // Test Case 2: [3,2,1] -> [1,2,3]
    std::vector<int> nums2 = {3, 2, 1};
    std::cout << "Input: [3,2,1]\n";
    nextPermutation_Manual(nums2);
    std::cout << "Output (Manual): ";
    for (int num : nums2) std::cout << num << " ";
    std::cout << "\n\n";

    // Test Case 3: [1,1,5] -> [1,5,1]
    std::vector<int> nums3 = {1, 1, 5};
    std::cout << "Input: [1,1,5]\n";
    nextPermutation_Manual(nums3);
    std::cout << "Output (Manual): ";
    for (int num : nums3) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}