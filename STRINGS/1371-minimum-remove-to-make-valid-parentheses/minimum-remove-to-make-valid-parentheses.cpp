class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string r;
        vector<int> p;
        for (char c : s) {
            if (c == '(') {
                p.push_back(r.size());
                r.push_back(c);
            } else if (c == ')') {
                if (!p.empty()) {
                    p.pop_back();
                    r.push_back(c);
                }
            } else {
                r.push_back(c);
            }
        }
        int len = 0;
        for (int i = 0, j = 0; j < r.length(); ++j) {
            if (i < p.size() && j == p[i]) {
                ++i;
            } else {
                r[len++] = r[j];
            }
        }
        return r.substr(0, len);
        
    }
};