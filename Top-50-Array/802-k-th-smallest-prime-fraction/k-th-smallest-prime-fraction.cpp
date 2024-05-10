bool operator<(const pair<pair<int, int>, pair<int, int>> &x, const pair<pair<int, int>, pair<int, int>> &y) {
    const auto& a = x.first, b = y.first;
    return a.first * b.second < b.first * a.second;
}

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const auto cmp = [&A](const pair<int, int> &x, const pair<int, int> &y) { 
            return A[x.first] * A[y.second] > A[y.first] * A[x.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 1; i < A.size(); ++i) {
            q.push({0, i});
        }
        for (;;) {
            if (--K == 0) {
                return {A[q.top().first], A[q.top().second]};
            }
            const int j = q.top().first + 1, i = q.top().second;
            q.pop();
            if (j < i) {
                q.push({j, i});
            }
        }
        return {0, 0};
    }
};