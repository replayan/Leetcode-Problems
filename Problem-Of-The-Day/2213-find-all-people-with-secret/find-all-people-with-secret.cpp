class Solution {

    int getf(vector<int>& f, unordered_set<int>& s, int x) {
        s.insert(x);
        return f[x] == x ? x : (f[x] = getf(f, s, f[x]));
    }

    void make(int x, int y, vector<int>& f, vector<int>& num,
              unordered_set<int>& s) {
        x = getf(f, s, x);
        y = getf(f, s, y);
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<int> num(n, 1), f(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        f[firstPerson] = 0;
        num[0] = 2;
        vector<bool> mark(n);
        mark[0] = mark[firstPerson] = true;
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        for (int i = 0; i < meetings.size();) {
            unordered_set<int> s;
            const int t = meetings[i][2];
            for (int j = i; j < meetings.size() && meetings[j][2] == t; ++j) {
                make(meetings[j][0], meetings[j][1], f, num, s);
            }
            for (; i < meetings.size() && meetings[i][2] == t; ++i) {
                mark[meetings[i][0]] =
                    mark[meetings[i][0]] ||
                    getf(f, s, meetings[i][0]) == getf(f, s, 0);
                mark[meetings[i][1]] =
                    mark[meetings[i][1]] ||
                    getf(f, s, meetings[i][1]) == getf(f, s, 0);
            }
            for (int x : s) {
                if (!mark[x]) {
                    f[x] = x;
                    num[x] = 1;
                }
            }
        }
        vector<int> r;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                r.push_back(i);
            }
        }
        return r;
    }
};