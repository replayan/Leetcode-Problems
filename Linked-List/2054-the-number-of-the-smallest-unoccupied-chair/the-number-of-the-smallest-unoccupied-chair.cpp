class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int n = times.size();
        vector<int> leaving(n);
        priority_queue<vector<int>> q;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            q.push({-times[i][0], i});
            leaving[i] = times[i][1];
            s.insert(i);
        }
        while (!q.empty()) {
            const int x = q.top()[1];
            q.pop();
            if (x < n) {
                const int y = *s.begin();
                if (x == targetFriend) {
                    return y;
                }
                s.erase(s.begin());
                q.push({-leaving[x], y + n});
            } else {
                s.insert(x - n);
            }
        }
        return -1;
    }
};