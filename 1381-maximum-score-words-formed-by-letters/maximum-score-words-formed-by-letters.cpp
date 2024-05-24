class Solution {
public:
    void dfs(const vector<vector<int>> &w, const vector<int> &score, vector<int> &have, int ind, int may, int& ans) {
        if (ind == w.size()) {
            ans = max(ans, may);
            return;
        }
        dfs(w, score, have, ind + 1, may, ans);
        for (int i = 0; i < 26; ++i) {
            if (have[i] < w[ind][i]) {
                return;
            }
        }
        for (int i = 0; i < 26; ++i) {
            have[i] -= w[ind][i];
        }
        dfs(w, score, have, ind + 1, may + score[ind], ans);
        for (int i = 0; i < 26; ++i) {
            have[i] += w[ind][i];
        }
        
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> have(26);
        for (char c : letters) {
            ++have[c - 'a'];
        }
        vector<vector<int>> w;
        vector<int> s;
        for (const auto &word : words) {
            vector<int> temp(26);
            int total = 0;
            for (char c : word) {
                ++temp[c - 'a'];
                total += score[c - 'a'];
            }
            w.push_back(temp);
            s.push_back(total);
        }
        int ans = 0;
        dfs(w, s, have, 0, 0, ans);
        return ans;
        
    }
};