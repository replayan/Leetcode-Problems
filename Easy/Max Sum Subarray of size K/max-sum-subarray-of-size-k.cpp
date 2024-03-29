//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long current_sum = 0;
        long long max_sum = INT_MIN;

        // Calculate the sum of first K elements
        for (int i = 0; i < K; ++i) {
            current_sum += Arr[i];
        }

        // Update max_sum
        max_sum = max(current_sum, max_sum);

        // Iterate through the array, starting from Kth element
        for (int i = K; i < N; ++i) {
            // Subtract the element going out of the window
            current_sum -= Arr[i - K];
            // Add the new element coming into the window
            current_sum += Arr[i];
            // Update max_sum
            max_sum = max(current_sum, max_sum);
        }

        return max_sum;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends