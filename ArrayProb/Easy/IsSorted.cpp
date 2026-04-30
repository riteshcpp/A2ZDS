/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.
Example 1
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.
Example 2
Input : nums = [1, 2, 1, 4, 5]
Output : false
Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
Now your turn!
Input : nums = [1,9,6,8,5,4,0]
Output:
Pick your answer
*/
#include <iostream>
#include <vector>
#include <algorithm>
// C++20 approach using ranges library 
bool isSorted(std::vector<int>& nums) {
    return std::ranges::is_sorted(nums);
}
// Traditional approach without using ranges library
bool isSorted(std::vector<int>& nums) {
    int size = nums.size();
    for (int i = 1; i < size; ++i) {
        if (nums[i] < nums[i - 1])
            return false;
    }
    return true;
}
int main()
{
	std::vector<int> nums = {1, 1, 1, 4, 5};
	std::cout << isSorted(nums);
	return 0;
}