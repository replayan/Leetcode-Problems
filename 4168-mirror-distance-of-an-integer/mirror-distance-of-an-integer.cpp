class Solution {
    int rev(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

public:
    int mirrorDistance(int n) { return abs(n - rev(n)); }
};