/*
Highest Occurring Element in an Array
Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.

Examples:
Input: nums = [1, 2, 2, 3, 3, 3]
Output: 3
Explanation: The number 3 appears the most (3 times). It is the most frequent element.

Input: nums = [4, 4, 5, 5, 6]
Output: 4
Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.

Input: nums = [2, 4, 3, 2, 5, 4]
Output: 2
Explanation: Both 2 and 4 appear twice, but 2 is smaller. So, 2 is the most frequent element.
*/
#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

int mostFrequentElement(vector<int>& nums) 
{
    std::unordered_map<int, int> freqMap;
    for (auto num : nums) freqMap[num]++;
    
    int maxFreq = INT_MIN;
    int num = INT_MAX; 
    for (auto [key, val] : freqMap) {
        if (val >= maxFreq && key <= num) {
            maxFreq = val;
            num = key;
        }
    }
    return num;
}
// optimised in single loop
int mostFrequentElement(vector<int>& nums) 
{
    std::unordered_map<int, int> freqMap;
    int maxFreq = INT_MIN;
    int maxNum = INT_MAX; 
    for (auto num : nums)
    {
        if (maxFreq <= ++freqMap[num] && num < maxNum)
        {
            maxFreq = freqMap[num];
            maxNum = num;
        }
    }
    return maxNum;
}
int main()
{
	std::vector<int> nums = {4, 4, 5, 5, 5, 6};
	std::cout << mostFrequentElement(nums);
	return 0;
}