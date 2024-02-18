// neetcode
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<vector<long long>> pq;
        const int m = meetings.size();
        for (int i = 0; i < m; ++i) {
            pq.push({-meetings[i][0], -1, i});
        }
        set<int> s;
        vector<int> room(n);
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        queue<int> q;
        while (!pq.empty()) {
            const long long now = pq.top()[0];
            const int t = pq.top()[1];
            const int id = pq.top()[2];
            pq.pop();
            if (t < 0) {
                if (s.empty()) {
                    q.push(id);
                } else {
                    const int rid = *s.begin();
                    s.erase(s.begin());
                    ++room[rid];
                    pq.push({-meetings[id][1], 1, -rid});
                }

            } else {
                s.insert(-id);
                if (!q.empty()) {
                    const int mid = q.front();
                    q.pop();
                    const int rid = -id;
                    s.erase(s.begin());
                    ++room[rid];
                    pq.push(
                        {now + meetings[mid][0] - meetings[mid][1], 1, -rid});
                }
            }
        }
        int ind = 0;
        for (int i = 1; i < n; ++i) {
            if (room[i] > room[ind]) {
                ind = i;
            }
        }
        return ind;
    }
};