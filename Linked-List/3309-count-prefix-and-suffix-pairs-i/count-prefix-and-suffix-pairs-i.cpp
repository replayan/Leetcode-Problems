class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (words[i].length() >= words[j].length() &&
                    words[i].substr(0, words[j].length()) == words[j] &&
                    words[i].substr(words[i].length() - words[j].length()) == words[j]) {
                    ++r;
                }
            }
        }
        return r;
    }
};