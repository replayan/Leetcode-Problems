class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        stack<char> word;
        string result;
        for (int i = 0; i < length; ++i) {
            if (s[i] != ' ') {
                word.push(s[i]);
            } else {
                while (!word.empty()) {
                    result += word.top();
                    word.pop();
                }
                result += ' ';
            }
        }
        while (!word.empty()) {
            result += word.top();
            word.pop();
        }
        return result;
    }
};
