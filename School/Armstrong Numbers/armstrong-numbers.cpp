//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string armstrongNumber(int n) {
        int originalNumber = n;
        int numDigits = 0;
        int sum = 0;
        
        // Count the number of digits
        while (n > 0) {
            n /= 10;
            numDigits++;
        }
        
        n = originalNumber; // Reset n to the original number
        
        // Calculate the sum of digits raised to the power of numDigits
        while (n > 0) {
            int digit = n % 10;
            sum += pow(digit, numDigits);
            n /= 10;
        }
        
        // Check if the sum is equal to the original number
        if (sum == originalNumber) {
            return "Yes";
        } else {
            return "No";
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends