# Infinite Sorted Array Search

This is a C++ implementation for finding the position of an element in an infinite sorted array. The problem becomes interesting due to the infinite nature of the array, which requires a modified binary search approach.

## Problem Description

Given an infinite sorted array `arr` that contains integers in ascending order and a target element `target`, the goal is to find the position (index) of the target element within the array.

## Approach

The key challenge is dealing with the infinite nature of the array. Here's how the algorithm works:

1. **Initial Bounds:** Start with two pointers, `low` and `high`, pointing to the first and second elements. Double the value of `high` until the target element might lie between `arr[low]` and `arr[high]`.

2. **Binary Search in the Range:** Perform a binary search within the current range. If the target element is found, return its index. If the target is less than `arr[mid]`, update `high = mid - 1`. If the target is greater than `arr[mid]`, update `low = mid + 1`.

3. **Doubling the Range:** If the target element is not in the current range, double the range by updating `low = high + 1` and doubling the value of `high`.

4. **Repeat:** Repeat steps 2 and 3 until the target element is found or determined to be not within the current range.

## Implementation

```cpp
int binary_search_infinite(const vector<int>& arr, int target, int low, int high) {
    while (arr[high] < target) {
        low = high + 1;
        high = high * 2;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Target element not found
}

int find_element_in_infinite_array(const vector<int>& arr, int target) {
    return binary_search_infinite(arr, target, 0, 1);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, ...};  // Infinite sorted array
    int target = 7;
    int position = find_element_in_infinite_array(arr, target);
    cout << "Position of " << target << " is " << position << endl;
    return 0;
}
