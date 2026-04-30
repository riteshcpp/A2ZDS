/*
Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.
This must be done in place, without making a copy of the array.
Example 1
Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation:
Both the zeroes are moved to the end and the order of the other elements stay the same
Example 2
Input: nums = [0, 0, 0, 1, 3, -2]
Output: [1, 3, -2, 0, 0, 0]
Explanation:
All 3 zeroes are moved to the end and the order of the other elements stay the same
Now your turn!
Input: nums = [0, 20, 0, -20, 0, 20]
Output: [20, -20, 20, 0, 0, 0]
Constraints
1 <= nums.length <= 105
-104 <=nums[i] <= 104
*/

#include <iostream>
#include <vector>
// Two Pointer Approach
void moveZeroes(std::vector<int>& nums) {
    int size = nums.size();
    int i = 0;
    // Find the first zero
    while(i < size && nums[i] != 0) ++i;
    // Swap non-zero elements with zeros
    for (int j = i+1; j < size; ++j) {
        if (nums[j] != 0) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
}

int main()
{
    std::vector<int> nums = {0,1,2,3,0};
    moveZeroes(nums);
    for (auto num : nums) std::cout << num << " ";
    return 0;
}