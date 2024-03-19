class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> have;
        for (char c : tasks) {
            ++have[c];
        }
        priority_queue<int> q1;
        priority_queue<vector<int>> q2;
        for (const auto& p : have) {
            q1.push(p.second);
        }
        int now = 0;
        while (!q1.empty() || !q2.empty()) {
            if (!q1.empty()) {
                int x = q1.top();
                q1.pop();
                if (--x) {
                    q2.push({now - n - 1, x});
                }
                --now;
            } else {
                now = min(now, q2.top()[0]);
            }
            while (!q2.empty() && q2.top()[0] >= now) {
                q1.push(q2.top()[1]);
                q2.pop();
            }
        }
        return -now;
    }
};