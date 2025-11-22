class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ascending; if end is the same, by start descending
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        // Initialize with the first interval
        int ans = 0;
        int a, b; 

        // First interval: greedily place at the right end
        int firstEnd = intervals[0][1];
        a = firstEnd - 1;
        b = firstEnd;
        ans = 2;

        // Process remaining intervals
        for (int i = 1; i < (int)intervals.size(); ++i) {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if (s <= a) {
                continue;
            } else if (s > b) {
                ans += 2;
                a = e - 1;
                b = e;
            } else {
                ans += 1;
                a = b;
                b = e;
            }
        }

        return ans;
    }
};
