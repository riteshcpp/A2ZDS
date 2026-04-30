/*
Selection Sort
Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.
Example 1
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.
Example 2
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
Explanation: 1 <= 1 <= 4 <= 4 <= 5.
Thus the array is sorted in non-decreasing order.
Now
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// print array method to display array elements
auto print = [](const auto &arr)
{
    for (const auto &x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
};

// selection sort method
// Logic: Select the position and find the smallest element in the unsorted array and swap it with the element at the selected position. Repeat this for all positions. Like selecting the first position, finding the smallest element in the entire array and swapping it with the first element. Then selecting the second position, finding the smallest element in the remaining unsorted array and swapping it with the second element. And so on.
// Time Complexity: O(n^2) for all cases (best, average, worst)
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Stability: Not Stable
// Adaptive: Not Adaptive
vector<int> selectionSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        int k = i;
        for (int j = i + 1; j < size; ++j) {
            if (nums[j] < nums[k])
                k = j;
        }
        std::swap(nums[k], nums[i]);
    }
    return nums;
}

// bubble sort method
// Logic: Repeatedly step through the list, compare adjacent elements and swap them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
// Time Complexity: O(n) for best case (when the array is already sorted), O(n^2) for average and worst cases
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Stability: Stable
// Adaptive: Yes, it can be optimized to stop if the array is already sorted
vector<int> bubbleSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        bool isSorted = true;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
    return nums;
}

// insertion sort method
// Logic: Consider the first element as sorted, then pick the next element and insert it into the sorted sequence at the correct position. Repeat this for all elements.
// Time Complexity: O(n) for best case (when the array is already sorted), O(n^2) for average and worst cases
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Stability: Stable
// Adaptive: Yes, it is adaptive as it performs better on partially sorted arrays
vector<int> insertionSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 1; i < size; ++i)
    {
        int k = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > k)
        {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = k;
    }
    return nums;
}

// merge sort
// Logic: Divide the array into two halves, recursively sort both halves, and then merge the sorted halves back together.
// Time Complexity: O(n log n) for all cases (best, average, worst)
// Space Complexity: O(n) as it requires additional space for the temporary arrays used in merging
// Stability: Stable
// Adaptive: Not Adaptive
void merge(vector<int> &nums, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= end)
        temp[k++] = nums[j++];

    for (int i = start, j = 0; i <= end; ++i, ++j)
        nums[i] = temp[j];
}
void mergeSorting(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSorting(nums, start, mid);
        mergeSorting(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}
vector<int> mergeSort(vector<int> &nums)
{
    int size = nums.size();
    mergeSorting(nums, 0, size - 1);
    return nums;
}

// quick sort methods
// Logic: Select the element and finding its correct position in the sorted array such that all elements smaller than the pivot are on the left side and all elements greater than the pivot are on the right side. Recursively apply the same logic to the left and right subarrays.
// Time Complexity: O(n log n) for average and best cases, O(n^2) for worst case (when the smallest or largest element is always chosen as the pivot)
// Space Complexity: O(log n) due to recursive stack space
// Stability: Not Stable
// Adaptive: Not Adaptive
int split(vector<int>& nums, int start, int end) {
    int pv = start;
    while (start < end)
    {
        // move start pointer to right until we find an element greater than pivot
        while (start < end && nums[pv] >= nums[start]) ++start;
        // move end pointer to left until we find an element smaller than pivot
        while (end >= start && nums[pv] < nums[end]) --end;
        if (start < end)
            std::swap(nums[start], nums[end]);
    }
    std::swap(nums[pv], nums[end]);
    return end;
}
void qSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int pv = split(nums, start, end);
        qSort(nums, start, pv - 1);
        qSort(nums, pv + 1, end);
    }
}
vector<int> quickSort(vector<int>& nums) {
    int size = nums.size();
    qSort(nums, 0, size - 1);
    return nums;
}

// heap sort methods
// Logic: Build a max heap from the input data, then repeatedly extract the maximum element from the heap and rebuild the heap until all elements are sorted.
// Time Complexity: O(n log n) for all cases (best, average, worst)
// Space Complexity: O(1) as it is an in-place sorting algorithm
// Stability: Not Stable
// Adaptive: Not Adaptive
// max heapify method
void maxHeapify(vector<int>& nums, int size, int idx) {
    int largest = idx;
    int l = (idx * 2) + 1;
    int r = (idx * 2) + 2;
    // check if left child is larger than root
    if (l <= size && nums[l] > nums[largest]) largest = l;
    // check if right child is larger than largest so far
    if (r <= size && nums[r] > nums[largest]) largest = r;
    // if largest is not root, swap and continue heapifying
    if (largest != idx) {
        std::swap(nums[largest], nums[idx]);
        maxHeapify(nums, size, largest);
    }
}
// min heapify method
void minHeapify(vector<int>& nums, int size, int idx) 
{
    int smallest = idx;
    int l = (idx * 2) + 1;
    int r = (idx * 2) + 2;
    if (l <= size && nums[l] < nums[smallest]) smallest = l;
    if (r <= size && nums[r] < nums[smallest]) smallest = r;
    if (smallest != idx) {
        std::swap(nums[smallest], nums[idx]);
        minHeapify(nums, size, smallest);
    }
}
// heap sort method, first build the heap tree and then delete from heap to sort the elements
vector<int> heapSort(vector<int>& nums) {
    int size = nums.size();
    // create heap tree
    for (int i = size/2 - 1; i >= 0; --i)
        maxHeapify(nums, size - 1, i);

    // delete from heap to sort the elements
    for (int i = size - 1; i >= 0; --i) {
        std::swap(nums[0], nums[i]);
        maxHeapify(nums, i-1, 0);
    }
    return nums;
}

// counting sort method
// Logic: Count the occurrence of each unique element in the array, then calculate the position of each element in the sorted array based on the counts, and finally build the sorted array.
// Time Complexity: O(n + k) where n is the number of elements in the input array and k is the range of the input
// Space Complexity: O(k) for the count array
// Stability: Stable
// Adaptive: Not Adaptive
vector<int> countSort(vector<int>& nums) {
    int size = nums.size();
    std::vector<int> temp(size, 0);
    int maxElement = std::ranges::max(nums); // find the maximum element in the array
    vector<int> cnt(maxElement + 1, 0);

    // count occurrence of each element
    for (auto num : nums)
        cnt[num]++;

    // update count array to store position of each element in sorted array
    for (int i = 1; i <= maxElement; ++i)
        cnt[i] = cnt[i] + cnt[i - 1];

    // build the output array
    for (int i = size - 1; i >= 0; --i)
        temp[--cnt[nums[i]]] = nums[i];

    // copy the output array to nums array
    for (int i = 0; i < size; ++i)
        nums[i] = temp[i];

    return nums;
}

// radix sort method
// Logic: Sort the elements based on each digit, starting from the least significant digit to the most significant digit, using a stable sorting algorithm (like counting sort) for each digit.
// Time Complexity: O(d * (n + k)) where d is the number of digits in the maximum number, n is the number of elements in the input array, and k is the range of the input
// Space Complexity: O(n + k) for the temporary arrays used in counting sort
// Stability: Stable
// Adaptive: Not Adaptive
vector<int> countSort(vector<int>& nums, int pos) {
    int size = nums.size();
    std::vector<int> temp(size, 0);
    vector<int> cnt(10, 0);
    for (auto num : nums) // count occurrence of each digit
        ++cnt[(num / pos) % 10];
    for (int i = 1; i < 10; ++i) // update count array to store position of each digit in sorted array
        cnt[i] = cnt[i] + cnt[i - 1];
    for (int i = size - 1; i >= 0; --i) // build the output array based on current digit
        temp[--cnt[(nums[i] / pos) % 10]] = nums[i];
    for (int i = 0; i < size; ++i) // copy the output array to nums array
        nums[i] = temp[i];
    return nums;
}
vector<int> radixSort(vector<int>& nums)
{
    // find the size of the array
    int size = nums.size();
    // find the maximum element in the array
    int max = std::ranges::max(nums);
    // do counting sort for every digit
    for (int pos = 1; max / pos > 0; pos *= 10)
        countSort(nums, pos);
    return nums;
}

int main()
{
    int choice;
    do
    {
        std::vector<int> nums = {7, 12, 8, 1, 3, 6, 15, 1};
        std::cout << "1\tBubble\n2\tinsertion\n3\tselection\n4\tquick\n5\tmerge\n7\theap sort\n8\tcount\n9\tRadix\n0\tfor exit\nYour Input: ";
        std::cin >> choice;
        std::cout << "array before sorting: ";
        print(nums);
        switch (choice)
        {
        case 1:
            bubbleSort(nums);
            break;
        case 2:
            insertionSort(nums);
            break;
        case 3:
            selectionSort(nums);
            break;
        case 4:
            quickSort(nums);
            break;
        case 5:
            mergeSort(nums);
            break;
        case 7:
            heapSort(nums);
            break;
        case 8:
            countSort(nums);
            break;
        case 9:
            radixSort(nums);
            break;
        default:
            break;
        }
        std::cout << "array after sorting: ";
        print(nums);
        std::cout << std::endl;
    } while (choice != 0);
}