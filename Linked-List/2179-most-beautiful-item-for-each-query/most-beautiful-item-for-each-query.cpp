class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        const int n = queries.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(),
             [&](const int x, const int y) { return queries[x] < queries[y]; });
        sort(items.begin(), items.end());
        const int m = items.size();
        vector<int> r(n);
        for (int i = 0, j = 0, v = 0; i < n; ++i) {
            for (; j < m && queries[ind[i]] >= items[j][0];
                 v = max(v, items[j++][1]))
                ;
            r[ind[i]] = v;
        }
        return r;
    }
};