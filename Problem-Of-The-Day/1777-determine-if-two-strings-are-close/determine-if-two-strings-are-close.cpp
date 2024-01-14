class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        vector<int> have1(26);
        for (int x : word1) {
            ++have1[x - 'a'];
        }
        vector<int> have2(26);
        for (int x : word2) {
            ++have2[x - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (!!have1[i] != !!have2[i]) return false;
        }
        sort(have1.begin(), have1.end());
        sort(have2.begin(), have2.end());
        return have1 == have2;
        
    }
};