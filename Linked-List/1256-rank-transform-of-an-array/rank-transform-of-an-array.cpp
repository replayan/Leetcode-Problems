class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(), a.end());
        map<int, int> r;
        for (int i = 0, j = 0; i < a.size(); ++i) {
            if (i == 0 || a[i] > a[i - 1]) {
                r[a[i]] = ++j;
            }
        }
        for (int& x : arr) {
            x = r[x];
        }
        return arr;
    }
};