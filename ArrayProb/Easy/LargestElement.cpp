/*
Given an array of integers nums, return the value of the largest element in the array
Example 1
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
Example 2
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99
Now your turn!
Input: nums = [-4, -3, 0, 1, -8]
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// largest element in an array method
int largestElement(vector<int> &nums) {
    int max = INT_MIN;
    for (auto num : nums) {
        if (num > max)
            max = num;
    }
    return max;
}
int main() {
    vector<int> nums = {3, 5, 7, 2, 8, -1, 4};
    cout << "The largest element in the array is: " << largestElement(nums) << endl;
    return 0;
}