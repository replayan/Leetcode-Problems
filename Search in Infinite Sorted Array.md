# Search in Infinite Sorted Array

Welcome to the enticing world of **Search in Infinite Sorted Array**! 🔍✨ Unleash the power of C++ functions to tackle this captivating problem. Whether you're a coding enthusiast or a problem-solving connoisseur, this readme is your guide to mastering the art of search in an infinite sorted array.

## The Problem

Imagine an array that stretches to infinity, where each element is sorted in ascending order. Your mission, should you choose to accept it, is to find a target element in this alluring, infinite array. But fear not, for we have not one, not two, but three tantalizing approaches for you to savor!

## Brute Force Approach 🏹

In the world of algorithms, sometimes simplicity is the ultimate sophistication. The brute force approach beckons you to traverse the infinite array one step at a time, looking for your desired target. While it might seem audacious, this approach's raw power can astound even the most seasoned programmers.

```cpp
int bruteForceSearch(const vector<int>& arr, int target) {
    int idx = 0;
    while (arr[idx] != target) {
        idx++;
    }
    return idx;
}
```

## Better Approach 🚀

Rise above the mundane with the "Better Approach." Harness the power of exponential growth to bound your search within a manageable range. This approach lets you hone in on your target with ever-increasing bounds, shrinking the search space like a gravitational pull towards success.

```cpp
int betterSearch(const vector<int>& arr, int target) {
    int left = 0, right = 1;

    while (arr[right] < target) {
        left = right;
        right *= 2;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}
```

## Best Approach 🌟

Prepare to be dazzled by the elegance of the "Best Approach." This technique is a symphony of binary search mastery, gracefully dancing through the infinite array with precision. It's a true testament to the artistry of problem-solving.

```cpp
int bestSearch(const vector<int>& arr, int target) {
    int left = 0, right = INT_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}
```

## Conclusion

Brace yourself for an unforgettable journey through the realm of infinite sorted arrays. Armed with the C++ functions and our trio of search techniques, you're now equipped to explore, conquer, and prevail in the face of the infinite unknown. Remember, every search is a step closer to unveiling the secrets hidden within the infinite expanse.

Now, go forth, intrepid coder, and may your searches be swift, your algorithms efficient, and your solutions nothing short of spectacular! 🚀🔥

_"Embrace the challenge, master the search."_ 🌌
