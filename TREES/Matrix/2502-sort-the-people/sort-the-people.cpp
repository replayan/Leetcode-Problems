class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = size(names);
        unordered_map<int, string> pr;
        for (int i = 0; i < n; ++i) {
            pr[heights[i]] = names[i];
        }
        sort(begin(heights), end(heights), greater<int>());
        for (int i = 0; i < n; i++) {
            names[i] = pr[heights[i]];
        }
        return names;
    }
};