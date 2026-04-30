/*
560. Subarray Sum Equals 
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Examples:
Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
Input: arr[] = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Logic: Use a hash map to store the frequency of prefix sums. For each prefix sum, check if there exists a previous prefix sum such that their difference is k, indicating a sub-array summing to k.
// LeeCode Link: https://leetcode.com/problems/subarray-sum-equals-k/description/
// Time Complexity: O(n) as we traverse the array once.
// Space Complexity: O(n) for storing prefix sums in the hash map.
int subarraySum(vector<int>& nums, int k) {
	std::unordered_map<int, int> preSum;
	preSum[0] = 1;
	int sum = 0, cnt = 0;
	for (auto num : nums) {
		sum += num;
		cnt += preSum[sum - k];
		preSum[sum]++;
	}
	return cnt;
}

int main()
{
// 	std::vector<int> nums = {1,1,1}; // k=2 Expected output: 2
	std::vector<int> nums = {1, 2, 3}; // k=3 Expected output: 2
	std::cout << subarraySum(nums, 3);
	return 0;
}