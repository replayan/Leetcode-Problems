class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, -1);
        const int n = s.length();
        for (int i = 0; i < n; ++i) {
            v[s[i] - 'a'] = i;
        }
        vector<int> r;
        for (int i = 0; i < n;) {
            const int j = i;
            for (int e = i; i <= e; e = max(e, v[s[i++] - 'a']))
                ;
            r.push_back(i - j);
        }
        return r;
    }
};