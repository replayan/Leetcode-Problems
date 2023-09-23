class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c==')'){
                if(st.size()>0 && st.top()=='('){ // if stack is not empty 
                    st.pop();
                } else{
                    st.push(c);
                }
            } else{
                st.push(c);
            }
        }
        return st.size();
    }
};