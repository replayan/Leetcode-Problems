class Solution {
    bool check(const string& s, string& t, int now,
               const unordered_set<string>& all) {
        if (now >= s.length()) {
            string temp(t);
            sort(temp.begin(), temp.end());
            return all.find(temp) != all.end();
        }
        if (check(s, t, now + 1, all)) {
            return true;
        }
        t.push_back(s[now]);
        const bool r = check(s, t, now + 1, all);
        t.pop_back();
        return r;
    }

public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> v(26);
        for (const auto& s : B) {
            vector<int> t(26);
            for (char c : s) {
                ++t[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                v[i] = max(v[i], t[i]);
            }
        }
        vector<string> r;
        for (const auto& s : A) {
            vector<int> p(26);
            for (char c : s) {
                ++p[c - 'a'];
            }
            bool mark = true;
            for (int i = 0; mark && i < 26; ++i) {
                mark = p[i] >= v[i];
            }
            if (mark) {
                r.push_back(s);
            }
        }
        return r;
    }
};