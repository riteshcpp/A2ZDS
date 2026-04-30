/*
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
Example 1
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation:
The largest value in nums is 8, the second largest is 7
Example 2
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation:
The only value in nums is 10, so there is no second largest value, thus -1 is returned
Now your turn!
Input: nums = [7, 7, 2, 2, 10, 10, 10]
Output:
Pick your answer
*/

#include <iostream>
#include <vector>
#include <climits>

int secondLargestElement(std::vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (auto num : nums) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        }
        else if (num > max2 && num != max1) {
            max2 = num;
        }
    }
    if (max2 == INT_MIN) return -1;
    return max2;
}
int main()
{
    std::vector<int> nums = {7, 7, 2, 2, 10, 10, 10};
    std::cout << secondLargestElement(nums);
    return 0;
}