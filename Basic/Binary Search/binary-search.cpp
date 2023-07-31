//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
public:
    int binarysearch(int arr[], int n, int k) {
        int left = 0; // Left boundary of the search interval.
        int right = n - 1; // Right boundary of the search interval.

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle index.

            if (arr[mid] == k) {
                return mid; // Element found, return the index.
            } else if (arr[mid] < k) {
                left = mid + 1; // Move the left boundary to the right half.
            } else {
                right = mid - 1; // Move the right boundary to the left half.
            }
        }

        return -1; // Element not found, return -1.
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends