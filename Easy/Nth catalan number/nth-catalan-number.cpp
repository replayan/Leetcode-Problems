//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        if (n <= 1)
            return 1;

        // Create a dynamic programming array to store the Catalan numbers.
        int MOD = 1000000007;
        int catalan[n + 1];
        catalan[0] = 1;
        catalan[1] = 1;

        // Calculate Catalan numbers using dynamic programming.
        for (int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++) {
                catalan[i] = (catalan[i] + (1LL * catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
            }
        }

        // The nth Catalan number modulo MOD will be stored in catalan[n].
        return catalan[n];
    }
};



//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends