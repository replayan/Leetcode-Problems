class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> v;
        for (int i = 0; i + 1 < weights.size(); ++i) {
            v.push_back(weights[i] + weights[i + 1]);
        }
        sort(v.begin(), v.end());
        --k;
        long long r = 0;
        for (int i = 0, j = v.size() - 1; k; --k, ++i, --j) {
            r += v[j] - v[i];
        }
        return r;
    }
};