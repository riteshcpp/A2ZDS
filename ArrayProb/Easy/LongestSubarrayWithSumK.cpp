/*
Longest subarray with sum K
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Example 1
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation:
The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
Example 2
Input: nums = [-3, 2, 1], k=6
Output: 0
Explanation:
There is no sub-array in the array that sums to 6. Therefore, the output is 0.
Now your turn!
Input: nums = [-1, 1, 1], k=1
Output: 3
Constraints
 1<=n<=105
 -105<=nums[i]<=105
 -109<= k<=109
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// For non-negative numbers only
// Time Complexity: O(n) Space Complexity: O(1)
// Logic: Use a sliding window approach to maintain a window with sum equal to k. Expand the window by moving the right pointer and contract it by moving the left pointer when the sum exceeds k.
int longestSubarray(std::vector<int> &nums, int k) {
	int maxLen = 0, sum = 0;
	int size = nums.size();
	for (int l = 0, r = 0; r < size; ++r) {
		sum += nums[r];
		if (sum > k) {
			sum -= nums[l++];
		}
		if (sum == k) {
			maxLen = std::max(maxLen, (r - l + 1));
		}
	}
	return maxLen;
}

// For negative numbers also
// Time Complexity: Average O(n), Worst O(n^2) (due to hash collisions)
// Space Complexity: O(n)
// Logic: Use a hash map to store the prefix sums and their earliest indices. For each prefix sum, check if there exists a previous prefix sum such that their difference is k, indicating a sub-array summing to k.
int longestSubarray(std::vector<int> &nums, int k) {
	int sum = 0, len = 0;
	int size = nums.size();
	std::unordered_map<int, int> preSumMap;
	for (int i = 0; i < size; ++i) {
		sum += nums[i];
		if (sum == k) {
			len = std::max(len, i + 1);
		}
		auto itr = preSumMap.find(sum - k);
		if (itr != preSumMap.end()) {
		    len = std::max(len, i - itr->second);
		}
		if (itr == preSumMap.end()) {
		    preSumMap[sum] = i;
		}
	}
	return len;
}

int main()
{
	std::vector<int> nums = {10, 5, 2, 7, 1, -10}; // k = 15, output = 6
	// std::vector<int> nums = {1, 1, -1}; // k = 1, output = 3
    // std::vector<int> nums = {-3, 2, 1}; // k = 6, output = 0
	std::cout << longestSubarray(nums, 15);

	return 0;
}