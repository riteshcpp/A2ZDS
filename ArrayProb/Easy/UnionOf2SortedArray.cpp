/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
Example 1
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation:
The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2
Example 2
Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation:
The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
Now your turn!
Input: nums1 = [3, 4, 4, 4], nums2 = [6, 7, 7]
Output:
Pick your answer
[3, 4, 6, 7, 7]
[3, 4, 6, 7]
[3, 4, 4, 4, 6, 7, 7]
[3 ,6, 4, 7]
Constraints
1 <= nums1.length, nums2.length <= 1000
-104 <= nums1[i] , nums2[i] <= 104
Both nums1 and nums2 are sorted in non-decreasing order
*/

#include <iostream>
#include <vector>
// Union of Two Sorted Arrays
std::vector<int> unionArray(std::vector<int>& nums1, std::vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();
	std::vector<int> res;
	int i = 0, j = 0;
	while(i < size1 && j < size2) {
		if (nums1[i] <= nums2[j]) {
			if (res.size() == 0 || res.back() != nums1[i])
				res.push_back(nums1[i]);
			++i;
		}
		else {
			if (res.size() == 0 || res.back() != nums2[j])
				res.push_back(nums2[j]);
			++j;
		}
	}
	while(i < size1) {
		if (res.back() != nums1[i])
			res.push_back(nums1[i]);
		++i;
	}
	while(j < size2) {
		if (res.back() != nums2[j])
			res.push_back(nums2[j]);
		++j;
	}
	return res;
}
// Intersection of Two Sorted Arrays
// Intersection means common elements in both arrays i.e. {7, 8, 8, 9} and {7, 8, 8, 8, 9} have intersection as {7, 8, 9}
std::vector<int> IntersectArray(std::vector<int>& nums1, std::vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    std::vector<int> res;
    int i = 0, j = 0;
    while(i < size1 && j < size2) {
        if (nums1[i] < nums2[j])
            ++i;
        else if (nums2[j] < nums1[i])
            ++j;
        else {
			// if (res.size() == 0 || res.back() != nums1[i]) 
            res.push_back(nums1[i]);
            ++i;
            ++j;
        }
    }
    return res;
}

int main()
{
	std::vector<int> nums1 = {3, 4, 6, 7, 8, 9, 9, 9, 10};
	std::vector<int> nums2 = {1, 5, 7, 8, 8, 8, 8, 9};
	auto nums = IntersectArray(nums1, nums2);
	for (auto num : nums) std::cout << num << " ";
	return 0;
}