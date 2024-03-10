//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_set<char> st;
	    string res;
	    for(char c:str){
	        if(st.find(c)==st.end()){
	            res.push_back(c);
	            st.insert(c);
	        }
	    }
	    return res;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends