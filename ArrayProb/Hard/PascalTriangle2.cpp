/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown: 
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:
Input: rowIndex = 0
Output: [1]
Example 3:
Input: rowIndex = 1
Output: [1,1]
Constraints:
0 <= rowIndex <= 33
Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/
//Tutorial Link: https://www.youtube.com/watch?v=bR7mQgwQ_o8

#include <iostream>
#include <vector>

// Logic: Each element in the row can be computed using the binomial coefficient formula: C(rowIndex, col) = rowIndex! / (col! * (rowIndex - col)!). We can compute this iteratively to avoid large factorials.
// Time Complexity: O(rowIndex) as we perform rowIndex iterations.
// Space Complexity: O(rowIndex) for storing the result.
// LeetCode Link: https://leetcode.com/problems/pascals-triangle-ii/description/
std::vector<int> getRow(int rowIndex) {
    std::vector<int> res;
    res.push_back(1);
    long long ans = 1;
    for (int col = 0; col < rowIndex; ++col) {
        ans = ans * (rowIndex - col);
        ans = ans / (col + 1);
        res.push_back(ans);
    }
    return res;
}

int main() {
    // Example 1: rowIndex = 3
    std::vector<int> result1 = getRow(3);
    std::cout << "Input: rowIndex = 3\nOutput: [";
    for (int i = 0; i < result1.size(); ++i) {
        std::cout << result1[i];
        if (i < result1.size() - 1) std::cout << ",";
    }
    std::cout << "]\n\n";

    // Example 2: rowIndex = 0
    std::vector<int> result2 = getRow(0);
    std::cout << "Input: rowIndex = 0\nOutput: [";
    for (int i = 0; i < result2.size(); ++i) {
        std::cout << result2[i];
        if (i < result2.size() - 1) std::cout << ",";
    }
    std::cout << "]\n\n";

    // Example 3: rowIndex = 1
    std::vector<int> result3 = getRow(1);
    std::cout << "Input: rowIndex = 1\nOutput: [";
    for (int i = 0; i < result3.size(); ++i) {
        std::cout << result3[i];
        if (i < result3.size() - 1) std::cout << ",";
    }
    std::cout << "]\n";

    return 0;
}