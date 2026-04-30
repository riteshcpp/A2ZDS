/*
Leaders in an Array
Given an integer array nums, return a list of all the leaders in the array.
A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.
Example 1
Input: nums = [1, 2, 5, 3, 1, 2]
Output: [5, 3, 2]
Explanation:
2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]
Example 2
Input: nums = [-3, 4, 5, 1, -4, -5]
Output: [5, 1, -4, -5]
Explanation:
-5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]
Now your turn!
Input: nums = [-3, 4, 5, 1, -30, -10]
Output: [5, 1, -10]
Constraints
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Logic: Reverse the array and keep track of the maximum element seen so far because in the reversed array, the leaders will be the elements which are greater than all the elements to their left. Finally, reverse the result array to maintain the original order.
std::vector<int> leaders(std::vector<int> &nums)
{
    std::reverse(nums.begin(), nums.end());
    std::vector<int> res;
    res.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > nums[i - 1])
            res.push_back(nums[i]);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    std::vector<int> nums = {1, 2, 5, 3, 1, 2}; // Expected output: [5, 3, 2]
    std::vector<int> nums = {-3, 4, 5, 1, -4, -5}; // Expected output: [5, 1, -4, -5]
    std::vector<int> nums = {-3, 4, 5, 1, -30, -10}; // Expected output: [5, 1, -10]
    auto res = leaders(nums);
    for (auto num : res)
        std::cout << num << " ";
    return 0;
}