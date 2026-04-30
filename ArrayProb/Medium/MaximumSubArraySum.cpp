/*
Kadane's Algorithm
Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1
Input: nums = [2, 3, 5, -2, 7, -4]
Output: 15
Explanation:
The subarray from index 0 to index 4 has the largest sum = 15
Example 2
Input: nums = [-2, -3, -7, -2, -10, -4]
Output: -2
Explanation:
The element on index 0 or index 3 make up the largest sum when taken as a subarray
Now your turn!
Input: nums = [-1, 2, 3, -1, 2, -6, 5]
Output: 
Constraints
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Return only maximum subarray sum
// LOGIC: If current sum becomes negative, reset it to 0, so that it doesn't affect future sums and keep track of the maximum sum encountered.
int maxSubArraySum(vector<int>& nums) {
    int sum = 0, max_sum = INT_MIN;
    for (auto num : nums) {
        sum += num;
        max_sum = max(sum, max_sum);
        if (sum < 0) sum = 0;
    }
    return max_sum;
}

// Return the starting and ending indices of the maximum subarray
pair<int, int> maxSubArrayIndices(const vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    int start = 0, end = 0, tempStart = 0;    
    for (int i = 0; i < nums.size(); ++i) {
        currentSum += nums[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    return {start, end};
}

int main() {
    vector<vector<int>> testCases = {
        {2, 3, 5, -2, 7, -4},
        {-2, -3, -7, -2, -10, -4},
        {-1, 2, 3, -1, 2, -6, 5}
    };    
    for (auto& nums : testCases) {
        int sum = maxSubArraySum(nums);
        auto [start, end] = maxSubArrayIndices(nums);        
        cout << "Array: ";
        for (int num : nums) cout << num << " ";
        cout << "\nMaximum Subarray Sum: " << sum;
        cout << "\nIndices: [" << start << ", " << end << "]\n\n";
    }
    return 0;
}
