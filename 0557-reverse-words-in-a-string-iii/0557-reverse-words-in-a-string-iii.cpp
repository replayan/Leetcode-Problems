class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        string str = "";
        vector<char> word;
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ') {
                for (int j = word.size() - 1; j >= 0; --j) {
                    str += word[j];
                }
                str += ' '; 
                word.clear(); 
            } else {
                word.push_back(s[i]); 
            }
        }
        for (int j = word.size() - 1; j >= 0; --j) {
            str += word[j];
        }
        return str;
    }
};