class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> mark(100000);
        for (const string &s : deadends) {
            mark[stoi(s)] = true;
        }
        if (mark[0]) {
            return -1;
        }
        const int want = stoi(target);
        if (want == 0) {
            return 0;
        }
        queue<int> q;
        q.push(0);
        mark[0] = true;
        const int w[] = {1, 10, 100, 1000};
        for (int step = 1; !q.empty(); ++step) {
            for (int s = q.size(); s; --s) {
                const int x = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    const int d = x / w[i] % 10;
                    for (int j = -1; j <= 1; ++j) {
                        if (j == 0) {
                            continue;
                        }
                        const int p = x + ((d + 10 + j) % 10 - d) * w[i];
                        if (p == want) {
                            return step;
                        }
                        if (!mark[p]) {
                            mark[p] = true;
                            q.push(p);
                        }

                    }

                }

            }
        }
        return -1;
    }
};