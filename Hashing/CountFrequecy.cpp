/*
Given an array nums of size n which may contain duplicate elements.
Return a list of pairs where each pair contains a unique element from the array and its frequency in the array.
You may return the result in any order, but each element must appear exactly once in the output.
Examples:
Input: nums = [1, 2, 2, 1, 3]
Output: [[1, 2], [2, 2], [3, 1]]
Explanation:
- 1 appears 2 times
- 2 appears 2 times
- 3 appears 1 time

Order of output can vary.
Input: nums = [5, 5, 5, 5]
Output: [[5, 4]]
Explanation:
- 5 appears 4 times.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

auto display = [](auto nums)
{
    for (auto freq : nums)
    {
        for (auto num : freq)
        {
            std::cout << num << "\t"; // << val << std::endl;
        }
        std::cout << std::endl;
    }
};

std::vector<std::vector<int>> countFrequencies(std::vector<int> &nums)
{
    std::unordered_map<int, int> freqMap;
    for (auto num : nums)
        freqMap[num]++;

    std::vector<std::vector<int>> result;
    for (auto [key, val] : freqMap)
        result.push_back({key, val});

    return result;
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 1, 3};
    auto result = countFrequencies(nums);
    display(result);

    return 0;
}