class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            const int x = s[i] - 'a';
            last[x] = i;
            if (first[x] < 0) {
                first[x] = i;
            }
        }
        int r = 0;
        for (int i = 0; i < 26; ++i) {
            if (last[i] > first[i]) {
                r += unordered_set<char>(s.begin() + first[i] + 1, s.begin() + last[i]).size();
            }
        }
        return r;
        
    }
};