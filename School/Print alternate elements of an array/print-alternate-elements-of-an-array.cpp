//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;




// } Driver Code Ends
//User function Template for C++

// ar[] is the array 
// n is the number of elements in array.

void print(int ar[], int n) {
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            res.push_back(ar[i]);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}


//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
  while(t--)
   {
     int ar[100001]={0};
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
      cin>>ar[i];
      print(ar,n);
      cout<<endl;
     }

return 0;
}

// } Driver Code Ends