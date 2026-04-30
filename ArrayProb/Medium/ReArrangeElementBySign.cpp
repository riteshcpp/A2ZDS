/*
Rearrange array elements by sign
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Example 1
Input : nums = [2, 4, 5, -1, -3, -4]
Output : [2, -1, 4, -3, 5, -4]
Explanation:
The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions
Example 2
Input : nums = [1, -1, -3, -4, 2, 3]
Output : [1, -1, 2, -3, 3, -4]
Explanation:
The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions
Now your turn!
Input: nums = [-4, 4, -4, 4, -4, 4]
Output: [4, -4, 4, -4, 4, -4]
Explanation:
The positive number 4, 4, 4 maintain their relative positions and -4, -4, -4 maintain their relative positions and start with positive number
Constraints
2 <= nums.length <= 105
1 <= | nums[i] | <= 104
nums.length is an even number.
Number of positive and negative numbers are equal.
*/

#include <iostream>
#include <vector>

// Version 1: Two-pointer approach with pre-allocated result array
// Time: O(n), Space: O(n)
// Uses two pointers (pos, neg) to place positive and negative numbers
// at alternating positions directly in the result array
std::vector<int> rearrangeArrayV1(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> res(size);
    int pos = 0, neg = 1;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > 0) {
            res[pos] = nums[i];
            pos += 2;
        }
        else {
            res[neg] = nums[i];
            neg += 2;
        }
    }
    return res;
}

// Version 2: Separate vectors approach
// Time: O(n), Space: O(n)
// First separates positive and negative numbers into two vectors,
// then merges them alternately back into the original array
std::vector<int> rearrangeArrayV2(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> pos;
    std::vector<int> neg;
    for (auto num : nums) {
        if (num > 0)
            pos.push_back(num);
        else
            neg.push_back(num);
    }
    for (int i = 0; i < pos.size(); ++i) {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }
    return nums;
}

// Client code with sample inputs
int main() {
    // Example 1
    std::vector<int> nums1 = {2, 4, 5, -1, -3, -4};
    std::vector<int> result1 = rearrangeArrayV1(nums1);
    std::cout << "Example 1 Output: ";
    for (int num : result1) std::cout << num << " ";
    std::cout << std::endl;
    
    // Example 2
    std::vector<int> nums2 = {1, -1, -3, -4, 2, 3};
    std::vector<int> result2 = rearrangeArrayV2(nums2);
    std::cout << "Example 2 Output: ";
    for (int num : result2) std::cout << num << " ";
    std::cout << std::endl;
    
    // Test case
    std::vector<int> nums3 = {-4, 4, -4, 4, -4, 4};
    std::vector<int> result3 = rearrangeArrayV1(nums3);
    std::cout << "Test case Output: ";
    for (int num : result3) std::cout << num << " ";
    std::cout << std::endl;
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:
Both versions have O(n) time and O(n) space complexity.

PERFORMANCE COMPARISON:
- Version 1 is BETTER for performance:
  * Single pass through input array
  * Direct placement in result array
  * Better cache locality
  * Lower memory overhead (only 1 extra vector)
  
- Version 2 is less efficient:
  * Two passes through data (separation + merge)
  * Creates 2 additional vectors
  * Higher memory overhead
  * More cache misses

RECOMMENDATION: Use Version 1 for optimal performance.
*/