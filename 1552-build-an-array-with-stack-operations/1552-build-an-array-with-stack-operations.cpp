class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> st;
        int i=1;
        for (int j=0; i<=n && j<target.size(); ++i) {
            st.push_back("Push");
            if (target[j]!=i){
                st.push_back("Pop");
            } else{
                j++;
            }
        }
        return st;
    }
};
