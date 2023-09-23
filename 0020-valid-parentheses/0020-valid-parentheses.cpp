class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // inserting
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                default:
                    return false;
            }
        }
        return st.empty();
    }
};
