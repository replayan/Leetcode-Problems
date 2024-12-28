class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + nums[i - 1];
        }
        puts("okay");
        vector<int> e(n);
        for (int i = k - 1; i + k + k <= n; ++i) {
            const int temp = p[i + 1] - p[i + 1 - k];
            e[i] = i;
            if (i >= k && temp <= p[e[i - 1] + 1] - p[e[i - 1] + 1 - k]) {
                e[i] = e[i - 1];
            }
            // printf("e[%d] = %d\n", i, e[i]);
        }
        vector<int> s(n);
        for (int i = n - k; i >= k + k; --i) {
            const int temp = p[i + k] - p[i];
            s[i] = i;
            if (i + 1 <= n - k && temp < p[s[i + 1] + k] - p[s[i + 1]]) {
                s[i] = s[i + 1];
            }
            // printf("s[%d] = %d\n", i, s[i]);
        }
        int may = 0;
        vector<int> r = {n, n, n};
        for (int i = k; i + k + k <= n; ++i) {
            // [i..i + k - 1]
            const int temp = p[e[i - 1] + 1] - p[e[i - 1] + 1 - k] + p[i + k] -
                             p[i] + p[s[i + k] + k] - p[s[i + k]];
            const vector<int> ind = {e[i - 1] - k + 1, i, s[i + k]};
            if (temp > may || (temp == may && ind < r)) {
                may = temp;
                r = ind;
            }
        }
        return r;
    }
};