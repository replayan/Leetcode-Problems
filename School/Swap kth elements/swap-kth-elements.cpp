//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // Swap k'th element from beginning and end
    void swapKth(int *arr, int n, int k) {
        // If k is out of the array bounds, return.
        if (k <= 0 || k > n) {
            return;
        }

        // Calculate the index of the k'th element from the end.
        int k_from_end = n - k;

        // If the elements are the same, no need to swap.
        if (k_from_end == k - 1) {
            return;
        }

        // Swap the elements.
        swap(arr[k - 1], arr[k_from_end]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.swapKth(arr, n, k);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends