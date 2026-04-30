/*
Majority Element-II
Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.
Example 1
Input: nums = [1, 2, 1, 1, 3, 2]
Output: [1]
Explanation:
Here, n / 3 = 6 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1]
Example 2
Input: nums = [1, 2, 1, 1, 3, 2, 2]
Output: [1, 2]
Explanation:
Here, n / 3 = 7 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1, 2]
Now your turn!
Input: nums = [1, 2, 1, 1, 3, 2, 2, 3](Give the solution sorted in ascending order)
Output: [1, 2]
Explanation:
Here, n / 3 = 8 / 3 = 2, therefore the elements appearing 3 or more times are : [1, 2]
Constraints
n == nums.length.
2 <= n <= 105
-104 <= nums[i] <= 104
*/
// Tutorial Link: https://www.youtube.com/results?search_query=229.+majority+element+ii

#include <iostream>
#include <vector>
#include <climits>

// Logic: As we are looking for elements that appear more than n/3 times, maximum two such elements can exist. Hence, the logic is that we maintain two candidate elements and their counts. We first find potential candidates using a modified Boyer-Moore Voting Algorithm, and then we verify these candidates by counting their occurrences in the array.
// Time Complexity: O(n) as we traverse the array twice.
// Space Complexity: O(1) as we use only constant extra space.
// LeetCode Link: https://leetcode.com/problems/majority-element-ii/description/
std::vector<int> majorityElement(std::vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (auto num : nums) {
        if (cnt1 == 0 && num != el2) {
            cnt1 = 1;
            el1 = num;
        } else if (cnt2 == 0 && num != el1) {
            cnt2 = 1;
            el2 = num;
        } else if (num == el1) {
            ++cnt1;
        } else if (num == el2) {
            ++cnt2;
        } else {
            --cnt1;
            --cnt2;
        }
    }
    // Verify the candidates
    cnt1 = 0, cnt2 = 0;
    for (auto num : nums) {
        if (num == el1) ++cnt1;
        if (num == el2) ++cnt2;
    }
    int min = nums.size() / 3;
    std::vector<int> res;
    if (cnt1 > min) res.push_back(el1);
    if (cnt2 > min) res.push_back(el2);
    return res;
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 2, 1, 1, 3, 2};
    std::vector<int> result1 = majorityElement(nums1);
    std::cout << "Example 1 - Output: ";
    for (int num : result1) std::cout << num << " ";
    std::cout << "\n";

    // Example 2
    std::vector<int> nums2 = {1, 2, 1, 1, 3, 2, 2};
    std::vector<int> result2 = majorityElement(nums2);
    std::cout << "Example 2 - Output: ";
    for (int num : result2) std::cout << num << " ";
    std::cout << "\n";

    // Your turn
    std::vector<int> nums3 = {1, 2, 1, 1, 3, 2, 2, 3};
    std::vector<int> result3 = majorityElement(nums3);
    std::cout << "Your turn - Output: ";
    for (int num : result3) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
