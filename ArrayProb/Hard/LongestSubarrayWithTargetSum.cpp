/*
Largest Subarray with Sum 0
You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.
Return the length of such a subarray. If no such subarray exists, return 0.
Example 1
Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation:
The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.
Example 2
Input: arr = [2, 10, 4]
Output: 0
Explanation:
There is no subarray whose elements sum to 0.
Now your turn!
Input: arr = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation:
The subarray [0, -4, 3, 1, 0] sums up to 0 and has the maximum length of 5.
Constraints
1 <= arr.length <= 106
-103 <= arr[i] <= 103 for each valid index i
Hints
Hint 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

// Logic: Use a hash map to store the prefix sums and their earliest indices. 
// For each prefix sum, check if there exists a previous prefix sum such that 
// their difference equals the target sum, indicating a sub-array with that sum.
// This implementation works for any target sum value. Currently targetSum = 0 
// finds the longest subarray with sum 0, but can be changed to find subarrays 
// with any other target sum. Also works with negative numbers and zeros.
// Time Complexity: Average O(n), Worst O(n^2) (due to hash collisions)
// Space Complexity: O(n)

int maxLen(std::vector<int>& arr)
{
    int size = arr.size();
    int length = 0, currSum = 0, targetSum = 0;
    std::unordered_map<int, int> preSum;
    for (int i = 0; i < size; ++i) {
        currSum += arr[i];
        if (currSum == targetSum) {
            length = std::max(length, i + 1);
        }
        auto itr = preSum.find(currSum - targetSum);
        if (itr != preSum.end()) {
            length = std::max(length, i - itr->second);
        } else {
            preSum[currSum] = i;
        }
    }
    return length;
}

// longest subarray length with sum k with starting and ending indices
std::tuple<int, int, int> maxLenWithIndices(std::vector<int>& arr, int k)
{
    int size = arr.size();
    int length = 0, currSum = 0;
    int start = -1, end = -1;
    std::unordered_map<int, int> preSum;
    for (int i = 0; i < size; ++i) {
        currSum += arr[i];
        if (currSum == k) {
            length = std::max(length, i + 1);
            start = 0;
            end = i;
        }
        auto itr = preSum.find(currSum - k);
        if (itr != preSum.end()) {
            if (length < i - itr->second) {
                length = i - itr->second;
                start = itr->second + 1;
                end = i;
            }
        } else {
            preSum[currSum] = i;
        }
    }
    return {length, start, end};
}

int main()
{
    // Test case 1: Example from problem
    std::vector<int> arr1 = {15, -2, 2, -8, 1, 7, 10, 23};
    int result1 = maxLen(arr1);
    auto [len1, start1, end1] = maxLenWithIndices(arr1, 0);
    std::cout << "Test 1: arr = [15, -2, 2, -8, 1, 7, 10, 23], "
              << "Expected: 5, Actual: " << result1 << ", Indices: [" << start1 << ", " << end1 << "]" << std::endl;
    assert(result1 == 5 && len1 == 5);

    // Test case 2: No subarray with sum 0
    std::vector<int> arr2 = {2, 10, 4};
    int result2 = maxLen(arr2);
    auto [len2, start2, end2] = maxLenWithIndices(arr2, 0);
    std::cout << "Test 2: arr = [2, 10, 4], "
              << "Expected: 0, Actual: " << result2 << ", Indices: [" << start2 << ", " << end2 << "]" << std::endl;
    assert(result2 == 0 && len2 == 0);

    // Test case 3: Given test case
    std::vector<int> arr3 = {1, 0, -4, 3, 1, 0};
    int result3 = maxLen(arr3);
    auto [len3, start3, end3] = maxLenWithIndices(arr3, 0);
    std::cout << "Test 3: arr = [1, 0, -4, 3, 1, 0], "
              << "Expected: 5, Actual: " << result3 << ", Indices: [" << start3 << ", " << end3 << "]" << std::endl;
    assert(result3 == 5 && len3 == 5);

    // Test case 4: Single element 0
    std::vector<int> arr4 = {0};
    int result4 = maxLen(arr4);
    auto [len4, start4, end4] = maxLenWithIndices(arr4, 0);
    std::cout << "Test 4: arr = [0], "
              << "Expected: 1, Actual: " << result4 << ", Indices: [" << start4 << ", " << end4 << "]" << std::endl;
    assert(result4 == 1 && len4 == 1);

    // Test case 5: Entire array sums to 0
    std::vector<int> arr5 = {-1, 1, -1, 1};
    int result5 = maxLen(arr5);
    auto [len5, start5, end5] = maxLenWithIndices(arr5, 0);
    std::cout << "Test 5: arr = [-1, 1, -1, 1], "
              << "Expected: 4, Actual: " << result5 << ", Indices: [" << start5 << ", " << end5 << "]" << std::endl;
    assert(result5 == 4 && len5 == 4);

    // Test case 6: Positive and negative pair
    std::vector<int> arr6 = {1, -1};
    int result6 = maxLen(arr6);
    auto [len6, start6, end6] = maxLenWithIndices(arr6, 0);
    std::cout << "Test 6: arr = [1, -1], "
              << "Expected: 2, Actual: " << result6 << ", Indices: [" << start6 << ", " << end6 << "]" << std::endl;
    assert(result6 == 2 && len6 == 2);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}