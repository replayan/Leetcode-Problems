class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.length();
        vector<int> r(n);
        for (int i = 0, s = 0, last = 0; i < n; ++i) {
            last += s;
            s += boxes[i] - '0';
            r[i] = last;
        }
        for (int i = n - 1, s = 0, last = 0; i >= 0; --i) {
            last += s;
            s += boxes[i] - '0';
            r[i] += last;
        }
        return r;
    }
};