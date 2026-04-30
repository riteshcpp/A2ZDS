/*
66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <vector>
#include <iostream>
#include <ranges>

// Logic: Traverse the digits from the end to the beginning. If a digit is 9, set it to 0 and continue. If a digit is less than 9, increment it by 1 and return the result. If all digits are 9, insert 1 at the beginning of the vector.
// Time Complexity: O(n), where n is the number of digits in the input array.
// Space Complexity: O(1), as we are modifying the input array in place.
// LeetCode: https://leetcode.com/problems/plus-one/description/
std::vector<int> plusOne(std::vector<int>& digits) {
    for (auto& num : digits | std::views::reverse) {
        if (num == 9) {
            num = 0;
        } else {
            num += 1;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    // Example 1
    std::vector<int> digits1 = {1, 2, 3};
    std::vector<int> result1 = plusOne(digits1);
    std::cout << "Input: [1,2,3]\nOutput: [";
    for (int i = 0; i < result1.size(); i++) {
        std::cout << result1[i];
        if (i < result1.size() - 1) std::cout << ",";
    }
    std::cout << "]\n\n";

    // Example 2
    std::vector<int> digits2 = {4, 3, 2, 1};
    std::vector<int> result2 = plusOne(digits2);
    std::cout << "Input: [4,3,2,1]\nOutput: [";
    for (int i = 0; i < result2.size(); i++) {
        std::cout << result2[i];
        if (i < result2.size() - 1) std::cout << ",";
    }
    std::cout << "]\n\n";

    // Example 3
    std::vector<int> digits3 = {9};
    std::vector<int> result3 = plusOne(digits3);
    std::cout << "Input: [9]\nOutput: [";
    for (int i = 0; i < result3.size(); i++) {
        std::cout << result3[i];
        if (i < result3.size() - 1) std::cout << ",";
    }
    std::cout << "]\n";

    return 0;
}