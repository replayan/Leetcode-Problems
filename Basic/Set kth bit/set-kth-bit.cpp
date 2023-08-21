//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    int setKthBit(int N, int K)
    {
        // Set the Kth bit to 1
        int mask = 1 << (K);  // Create a mask with the Kth bit set to 1
        int ans = N | mask;       // Use bitwise OR to set the Kth bit to 1
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends