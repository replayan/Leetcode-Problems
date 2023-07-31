//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // Function to return list containing first n fibonacci numbers from 1.
    vector<long long> printFibb(int n) 
    {
        vector<long long> fibonacci;
        
        if (n <= 0)
            return fibonacci; // Return an empty vector for invalid input.

        // The first Fibonacci number is 1.
        fibonacci.push_back(1);
        if (n == 1)
            return fibonacci;

        // The second Fibonacci number is 1.
        fibonacci.push_back(1);
        if (n == 2)
            return fibonacci;

        // Generate the remaining Fibonacci numbers.
        for (int i = 2; i < n; i++) {
            long long nextFibonacci = fibonacci[i - 1] + fibonacci[i - 2];
            fibonacci.push_back(nextFibonacci);
        }

        return fibonacci;
    }
};


//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends