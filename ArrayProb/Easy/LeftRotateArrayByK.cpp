/*
Given an integer array nums, rotate the array to the left by one.
Note: There is no need to return anything, just modify the given array.
Example 1
Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation:
Initially, nums = [1, 2, 3, 4, 5]
Rotating once to left -> nums = [2, 3, 4, 5, 1]
Example 2
Input: nums = [-1, 0, 3, 6]
Output: [0, 3, 6, -1]
Explanation:
Initially, nums = [-1, 0, 3, 6]
Rotating once to left -> nums = [0, 3, 6, -1]
Now your turn!
Input: nums = [7, 6, 5, 4]
Output:
Pick your answer
[5, 6, 4, 7]
[5, 4, 7, 6]
[6, 5, 4, 7]
[4, 7, 6, 5]
Constraints
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

// left rotate array by k positions using reversal algorithm
void rotateArrayByK(std::vector<int>& nums, int k) {
    if (k == 0) return; // no need to rotate
    int size = nums.size();
    k %= size; // in case k is greater than size of array
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
    std::reverse(nums.begin(), nums.end());
}
// left rotate array by k positions using std::ranges::rotate
void rotateArrayByK(std::vector<int>& nums, int k) {
    k %= nums.size();
    if (k == 0) return;    
    std::ranges::rotate(nums, nums.begin() + k); // rotate left by k positions
}
// client code
int main()
{
    std::vector<int> nums = {1,2,3,4,5};
	rotateArrayByK(nums, 1);
	for_each(nums.begin(), nums.end(), [](int num){std::cout << num << " ";});
	return 0;
}