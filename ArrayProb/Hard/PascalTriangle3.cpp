/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:
Input: numRows = 1
Output: [[1]]
Constraints:
1 <= numRows <= 30
*/

//Tutorial Link: https://www.youtube.com/watch?v=bR7mQgwQ_o8

#include <iostream>
#include <vector>

// Logic: Each row can be generated using the binomial coefficient formula: C(row-1, col) = (row-1)! / (col! * (row-1-col)!). We can compute this iteratively to avoid large factorials.
// Time Complexity: O(numRows^2) as we generate each element in the triangle.
// Space Complexity: O(numRows^2) for storing the result.
// LeetCode Link: https://leetcode.com/problems/pascals-triangle/description/
std::vector<int> rowGen(int row) {
    std::vector<int> res;
    res.push_back(1);
    int ans = 1;
    for (int col = 1; col < row; ++col) {
        ans = ans * (row - col);
        ans = ans / col;
        res.push_back(ans);
    }
    return res;
}
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for (int row = 1; row <= numRows; ++row) {
        res.push_back(rowGen(row));
    }
    return res;
}

int main() {
    // Example 1: numRows = 5
    std::vector<std::vector<int>> result1 = generate(5);
    std::cout << "Output for numRows = 5:\n";
    for (const auto& row : result1) {
        std::cout << "[";
        for (int i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << ",";
        }
        std::cout << "]\n";
    }

    // Example 2: numRows = 1
    std::vector<std::vector<int>> result2 = generate(1);
    std::cout << "\nOutput for numRows = 1:\n";
    for (const auto& row : result2) {
        std::cout << "[";
        for (int i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i < row.size() - 1) std::cout << ",";
        }
        std::cout << "]\n";
    }

    return 0;
}