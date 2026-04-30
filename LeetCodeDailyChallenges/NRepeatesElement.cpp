/*
961. N-Repeated Element in Size 2N Array
You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
Example 1:
Input: nums = [1,2,3,3]
Output: 3
Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2
Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
Constraints:
2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
nums contains n + 1 unique elements and one of them is repeated exactly n times.
*/

#include <iostream>
#include <vector>

int repeatedNTimes(std::vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (nums[i] == nums[i + 1]) {
            return nums[i];
        } else if (i + 2 < size && nums[i] == nums[i + 2]) {
            return nums[i];
        } else if (i + 3 < size && nums[i] == nums[i + 3]) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 2, 3, 3};
    std::cout << "Example 1: " << repeatedNTimes(nums1) << std::endl;
    
    // Example 2
    std::vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    std::cout << "Example 2: " << repeatedNTimes(nums2) << std::endl;
    
    // Example 3
    std::vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};
    std::cout << "Example 3: " << repeatedNTimes(nums3) << std::endl;
    
    return 0;
}