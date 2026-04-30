/*
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.
Return the number of unique elements in the array.
If the number of unique elements be k, then,
Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.
The driver code will assess correctness by printing and checking only the first k elements of the modified array.
An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.
Example 1
Input: nums = [0, 0, 3, 3, 5, 6]
Output: 4
Explanation:
Resulting array = [0, 3, 5, 6, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.
Example 2
Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
Output: 4
Explanation:
Resulting array = [-2, 2, 4, 5, _, _, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.
Now your turn!
Input: nums = [-30, -30, 0, 0, 10, 20, 30, 30]
*/
#include <iostream>
#include <vector>
#include <algorithm>
// remove duplicates from sorted array
// LeetCode Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Logic: if current element is not equal to previous unique element, increment unique index and update the unique index with current element, so that all unique elements are at the start of the array.
int removeDuplicates(std::vector<int>& nums) {
	int size = nums.size();
	int i = 0;
	for (int j = 1; j < size; ++j) {
		if (nums[j] != nums[i])
			nums[++i] = nums[j];
	}
	return i+1;
}
int main()
{
// 	std::vector<int> nums = {0, 0, 3, 3, 5, 6};
//  std::vector<int> nums = {-2, 2, 4, 4, 4, 4, 5, 5};
    std::vector<int> nums = {1,2,3,4,5};
	int k = removeDuplicates(nums);
	std::cout << "Unique Element: " << k << std::endl;
	for_each(nums.begin(), nums.begin() + k, [](int num){std::cout << num << " ";});
	return 0;
}