class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (int i = 0; i < num.size(); ++i) {
            while (!st.empty() && st.back() > num[i] && k > 0) {
                st.pop_back();
                --k;
            }
            if (!st.empty() || num[i] != '0') {
                st.push_back(num[i]);
            }
        }
        while (!st.empty() && k > 0) {
            st.pop_back();
            --k;
        }
        if (st == "") {
            return "0";
        }
        return st;
    }
};
