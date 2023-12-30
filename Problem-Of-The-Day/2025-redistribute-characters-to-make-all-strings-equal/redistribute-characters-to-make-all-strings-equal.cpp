class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int n = words.size();
        vector<int> num(26, 0);
        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                char c = word[j];
                ++num[c - 'a'];
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (num[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};
