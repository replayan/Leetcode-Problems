class Solution {
    int getf(int x, vector<int>& f) {
        return (f[x] == x) ? x : (f[x] = getf(f[x], f));
    }

    void merge(int x, int y, vector<int>& f, vector<int>& num) {
        x = getf(x, f);
        y = getf(y, f);
        if (x == y) {
            return;
        }
        if (num[x] > num[y]) {
            swap(x, y);
        }
        f[x] = y;
        num[y] += num[x];
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> f(20002), num(20002);
        for (int i = 0; i < f.size(); ++i) {
            f[i] = i;
            num[i] = 1;
        }
        for (const auto& s : stones) {
            merge(s[0], s[1] + 10001, f, num);
        }
        unordered_set<int> all;
        for (const auto& s : stones) {
            all.insert(getf(s[0], f));
        }
        return stones.size() - all.size();
    }
};