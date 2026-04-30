/*
Majority Element-I
Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
Example 1
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
Output: 7
Explanation:
The number 7 appears 5 times in the 9 sized array
Example 2
Input: nums = [1, 1, 1, 2, 1, 2]
Output: 1
Explanation:
The number 1 appears 4 times in the 6 sized array
Now your turn!
Input: nums = [-1, -1, -1, -1]
Output:
Pick your answer
0
1
-1
4
Constraints
n == nums.length.
1 <= n <= 105
-104 <= nums[i] <= 104
One value appears more than n/2 times.
*/

#include <iostream>
#include <vector>
using namespace std;

// Boyer-Moore Voting Algorithm: how it works?  
// We maintain a count, which is incremented when we see an instance of our current candidate for majority element, and decremented when we see an instance of a different element. When the count reaches zero, we select the next element as our new candidate. Since the majority element appears more than n/2 times, it will always be the last remaining candidate.
// Time Complexity: O(n) Space Complexity: O(1)
int majorityElement(vector<int>& nums) {
    int size = nums.size();
    int cnt = 1, num = nums[0];
    for (int i = 1; i < size; ++i) {
        if (cnt == 0) {
            ++cnt;
            num = nums[i];
        }
        else if (nums[i] == num)
            ++cnt;
        else
            --cnt;
    }
    return num;
}

int main() {
    // Example 1
    vector<int> nums1 = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    cout << "Input: [7, 0, 0, 1, 7, 7, 2, 7, 7]" << endl;
    cout << "Output: " << majorityElement(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 1, 1, 2, 1, 2};
    cout << "\nInput: [1, 1, 1, 2, 1, 2]" << endl;
    cout << "Output: " << majorityElement(nums2) << endl;

    // Example 3
    vector<int> nums3 = {-1, -1, -1, -1};
    cout << "\nInput: [-1, -1, -1, -1]" << endl;
    cout << "Output: " << majorityElement(nums3) << endl;

    return 0;
}