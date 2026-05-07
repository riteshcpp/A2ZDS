/*
152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
Example 3:
Input: nums = [4, 5, 3, 7, 1, 2]
Output: 840
Explanation:
The largest product is given by the whole array itself
Example 4:
Input: nums = [-5, 0, -2]
Output: 0
Explanation:
The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].
Example 5:
Input: nums = [1, -2, 3, 4, -4, -3]
Output: 144
Explanation: The largest product is given by the subarray [3, 4, -4, -3] 
Constraints:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.*
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Logic: Traverse the array while maintaining two products: the product from the start and the product from the end. This helps to account for negative numbers which can turn a small product into a large one when multiplied by another negative number. And handle zeros by resetting the products to 1.
// LeetCode Link: https://leetcode.com/problems/maximum-product-subarray/description/
// Time Complexity: O(n) as we traverse the array once.
// Space Complexity: O(1) as we use only constant extra space.
int maxProduct(std::vector<int>& nums) {
    int prefixProduct = 1, suffixProduct = 1, result = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (prefixProduct == 0) prefixProduct = 1;
        if (suffixProduct == 0) suffixProduct = 1;

        prefixProduct *= nums[i];
        suffixProduct *= nums[n - i - 1];

        result = std::max(result, std::max(prefixProduct, suffixProduct));
    }
    return result;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {2, 3, -2, 4};
    std::cout << "Example 1: " << maxProduct(nums1) << std::endl;  // Output: 6

    // Example 2
    std::vector<int> nums2 = {-2, 0, -1};
    std::cout << "Example 2: " << maxProduct(nums2) << std::endl;  // Output: 0

    // Example 3
    std::vector<int> nums3 = {4, 5, 3, 7, 1, 2};
    std::cout << "Example 3: " << maxProduct(nums3) << std::endl;  // Output: 840

    // Example 4
    std::vector<int> nums4 = {-5, 0, -2};
    std::cout << "Example 4: " << maxProduct(nums4) << std::endl;  // Output: 0

    // Example 5
    std::vector<int> nums5 = {1, -2, 3, 4, -4, -3};
    std::cout << "Example 5: " << maxProduct(nums5) << std::endl;  // Output: 144

    return 0;
}