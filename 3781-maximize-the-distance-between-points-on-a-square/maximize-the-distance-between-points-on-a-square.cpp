class Solution {
    int check(const vector<int>& v, int side) {
        // up
        if (v[1] == side)
            return 0;
        // right
        if (v[0] == side)
            return 1;
        // down
        if (v[1] == 0)
            return 2;
        return 3;
    }

    int dist(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(),
             [&](const vector<int>& v1, const vector<int>& v2) {
                 const int c1 = check(v1, side), c2 = check(v2, side);
                 if (c1 != c2)
                     return c1 < c2;
                 switch (c1) {
                 case 0:
                     return v1[0] < v2[0];
                 case 1:
                     return v1[1] > v2[1];
                 case 2:
                     return v1[0] > v2[0];
                 case 3:
                     return v1[1] < v2[1];
                 }
                 return false;
             });
        const int n = points.size();
        int left = 1, right = side + side;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            vector<int> f(n, -1);
            for (int i = 0, j = 0; i < n; ++i) {
                for (; j < n && dist(points[i], points[j]) < mid; ++j)
                    ;
                f[i] = j;
            }
            bool ok = false;
            for (int i = 0; !ok && i + k <= n; ++i) {
                int need = k - 1;
                for (int j = f[i];
                     need && j < n && dist(points[j], points[i]) >= mid;
                     j = f[j], --need)
                    ;
                ok = need == 0;
            }
            if (ok) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};