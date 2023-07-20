class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s, r;
        for (int x : asteroids) {
            if (x > 0) {
                s.push_back(x);
            } else {
                while (!s.empty() && x < 0) {
                    const int temp = x + s.back();
                    if (temp > 0) {
                        x = 0;
                    } else {
                        s.pop_back();
                        if (temp == 0) {
                            x = 0;
                        }
                    }
                }
                if (x < 0) {
                    r.push_back(x);
                }
            }
        }
        for (int x : s) {
            r.push_back(x);
        }
        return r;
    }
};