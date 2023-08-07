//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int find_median(vector<int> v) {
        // Sorting the array in ascending order
        sort(v.begin(), v.end());

        int n = v.size();
        int left = 0;
        int right = n - 1;
        int mid = left + (right - left) / 2; // Calculate the index of the middle element

        // If the array size is odd, the median is the middle element
        // If the array size is even, the median is the average of the middle two elements
        if (n % 2 == 1) {
            return v[mid];
        } else {
            return (v[mid] + v[mid + 1]) / 2;
        }
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends