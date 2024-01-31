class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(n,0);
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top()-i;
            }
            st.push(i);
        }
        return res;
    }
};