class Solution {
public:
    string reversePrefix(string word, char ch) {
        const char* chr = strchr(word.c_str(), ch);
        if (chr) {
            reverse(word.begin(), word.begin() + (chr - word.c_str()) + 1);
        }
        return word;
    }
};