class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int r = k;
        for (int i = 0, s = 0; i < blocks.size(); ++i) {
            s += blocks[i] == 'W';
            if (i >= k) {
                s -= blocks[i - k] == 'W';
            }
            if (i >= k - 1) {
                r = min(r, s);
            }
        }
        return r;
    }
};