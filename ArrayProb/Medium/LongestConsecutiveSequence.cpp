/*
128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:
Input: nums = [1,0,1,2]
Output: 3
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_set>

// Logic: Use a hash set to store the numbers for O(1) access. For each number, check if it's the start of a sequence (i.e., num - 1 is not in the set). If it is, count the length of the sequence by checking for consecutive numbers and update the maximum length found.
// Time Complexity: O(n) on average, as each number is processed at most twice.
// Space Complexity: O(n) for storing the numbers in the hash set.
int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> numset;
    int longest = 0;
    // Insert all numbers into the set
    for (auto num : nums)
        numset.insert(num);
    for (auto num : numset)
    {
        if (!numset.contains(num - 1)) // we can use count, find or contains to check presence in set
        {
            int currLen = 1;
            while (numset.contains(++num))
                ++currLen;
            longest = std::max(longest, currLen);
        }
    }
    return longest;
}

int main()
{
    // 	std::vector<int> nums = {100, 4, 200, 1, 3, 2}; //Expected output: 4
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}; // Expected output: 9
    //	std::vector<int> nums = {1, 0, 1, 2 }; //Expected output: 3
    std::cout << longestConsecutive(nums);
    return 0;
}