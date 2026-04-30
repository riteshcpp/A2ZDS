/*
Best time to buy and sell stock
Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once.
The stock should be purchased before selling it, and both actions cannot occur on the same day.
Example 1
Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.
Example 2
Input: arr = [5, 4, 3, 2, 1]
Output: 0
Explanation: In this case, no transactions are made. Therefore, the maximum profit remains 0.
Now your turn!
Input: arr = [3, 8, 1, 4, 6, 2]
Output: 5
Constraints
1 <= n<= 105
0 <= arr[i] <= 106
*/

#include <iostream>
#include <vector>
#include <algorithm>

//Logic: Keep track of the minimum price seen so far and calculate the potential profit at each step. Update the maximum profit accordingly.
int maxProfit(std::vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    int size = prices.size();
    for (int i = 1; i < size; ++i) {
        int currentProfit = prices[i] - minPrice;
        maxProfit = std::max(currentProfit, maxProfit);
        minPrice = std::min(minPrice, prices[i]);
    }
    return maxProfit;
}

int main() {
    // Example 1
    std::vector<int> arr1 = {10, 7, 5, 8, 11, 9};
    std::cout << "Input: [10, 7, 5, 8, 11, 9]" << std::endl;
    std::cout << "Output: " << maxProfit(arr1) << std::endl << std::endl;

    // Example 2
    std::vector<int> arr2 = {5, 4, 3, 2, 1};
    std::cout << "Input: [5, 4, 3, 2, 1]" << std::endl;
    std::cout << "Output: " << maxProfit(arr2) << std::endl << std::endl;

    // Your turn
    std::vector<int> arr3 = {3, 8, 1, 4, 6, 2};
    std::cout << "Input: [3, 8, 1, 4, 6, 2]" << std::endl;
    std::cout << "Output: " << maxProfit(arr3) << std::endl;

    return 0;
}
