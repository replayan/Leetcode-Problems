//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int nthMagicNo(int n) { 
        //complete the function here
        const int MOD=1e9+7;
        long long int res=0;
        long long int base=5;
        while(n>0){
            long long int last=n&1;
            n=n>>1;
            res+=last*base;
            base=base*5;
        }
        return (res%MOD);
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthMagicNo(n) << endl;
    
    }
    return 0; 
} 
// } Driver Code Ends