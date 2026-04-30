/*
Count subarrays with given xor K
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
Example 1
Input : nums = [4, 2, 2, 6, 4], k = 6
Output : 4
Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]
Example 2
Input :nums = [5, 6, 7, 8, 9], k = 5
Output : 2
Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
Now your turn!
Input : nums = [5, 2, 9], k = 7
Output: 1
Explanation : The subarray having XOR of its elements as 7 is [5, 2]
Constraints
    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    1 <= k <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// Logic: Use a hash map to store the frequency of prefix XORs. For each prefix XOR, check if there exists a previous prefix XOR such that their XOR is k, indicating a sub-array with that XOR.
// Time Complexity: O(n) as we traverse the array once.
// Space Complexity: O(n) for storing prefix XORs in the hash map.

int subarraysWithXorK(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> preSum;
    preSum[0] = 1;
    int cnt = 0, sum = 0;
    for (auto num : nums) {
        sum ^= num;
        cnt += preSum[sum ^ k];
        preSum[sum] += 1;
    }
    return cnt;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {4, 2, 2, 6, 4};
    int k1 = 6;
    std::cout << "Example 1: " << subarraysWithXorK(nums1, k1) << std::endl; // Output: 4

    // Example 2
    std::vector<int> nums2 = {5, 6, 7, 8, 9};
    int k2 = 5;
    std::cout << "Example 2: " << subarraysWithXorK(nums2, k2) << std::endl; // Output: 2

    // Test case
    std::vector<int> nums3 = {5, 2, 9};
    int k3 = 7;
    std::cout << "Test case: " << subarraysWithXorK(nums3, k3) << std::endl;

    return 0;
}