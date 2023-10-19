class Solution {
    string processBackspaces(string &s) {
        string result;
        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result += c;
            }
        }
        return result;
    }
public:
    bool backspaceCompare(string S, string T) {
        return processBackspaces(S) == processBackspaces(T);
    }
};
