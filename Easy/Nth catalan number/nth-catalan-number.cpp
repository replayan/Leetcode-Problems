//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findCatalan(int n) {
        int MOD = 1000000007;

        long long catalan = 1;
        for (int i = 0; i < n; i++) {
            catalan = (catalan * 2 * (2 * i + 1)) % MOD;
            catalan = (catalan * modInverse(i + 2, MOD)) % MOD;
        }

        return static_cast<int>(catalan);
    }

private:
    long long modInverse(long long num, long long mod) {
        long long result = 1;
        long long exp = mod - 2;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * num) % mod;
            }
            num = (num * num) % mod;
            exp >>= 1;
        }

        return result;
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