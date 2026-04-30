/*
Two Sum
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.
Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.
Example 1
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation:
nums[0] + nums[1] = 1 + 6 = 7
Example 2
Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]
Explanation:
nums[1] + nums[5] = 3 + (-3) = 0
Now your turn!
Input: nums = [-6, 7, 1, -7, 6, 2], target = 3
Output:
Pick your answer
[0, 1]
[3, 6]
[1, 2]
[2, 5]
Constraints
2 <= nums.length <= 105
-104 <= nums[i] <= 104
-105 <= target <= 105
Only one valid answer exists.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// find two sum elements in an unsorted array
// Time Complexity: O(n) Space Complexity: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> mp;
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
		auto itr = mp.find(target - nums[i]);
		if (itr != mp.end()) {
			return {itr->second, i};
		}
		mp[nums[i]] = i;
	}
	return {};
}

// Logic: Two pointers approach for sorted array
// Time Complexity: O(n) Space Complexity: O(1)
// LeetCode link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
std::vector<int> twoSumSorted(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int sum = nums[left] + nums[right];
		if (sum == target) {
			return {left, right};
		} else if (sum < target) {
			++left;
		} else {
			--right;
		}
	}
	return {};
}

int main()
{
// 	std::vector<int> nums = {1, 6, 2, 10, 3}; // Target = 7
// 	std::vector<int> nums = {1, 3, 5, -7, 6, -3}; // Target = 0
    std::vector<int> nums = {-6, 7, 1, -7, 6, 2}; // Target = 3
	auto res = twoSum(nums, 3);
	for (auto num : res) std::cout << num << " ";
	return 0;
}
