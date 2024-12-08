class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int n = events.size();
        vector<int> ind1(n), ind2(n);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            ind1[i] = i;
            ind2[i] = i;
            r = max(r, events[i][2]);
        }
        sort(ind1.begin(), ind1.end(), [&](const int x, const int y) {
            return events[x][0] < events[y][0];
        });
        sort(ind2.begin(), ind2.end(), [&](const int x, const int y) {
            return events[x][1] < events[y][1];
        });
        for (int i = 0, j = 0, v = 0; i < n && j < n; ++i) {
            for (; j < n && events[ind2[j]][1] < events[ind1[i]][0];
                 v = max(v, events[ind2[j++]][2]))
                ;
            r = max(r, v + events[ind1[i]][2]);
        }
        return r;
    }
};