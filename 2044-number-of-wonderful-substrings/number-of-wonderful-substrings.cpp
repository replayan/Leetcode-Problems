class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> res(1024);
        res[0] = 1;
        int s = 0;
        long long r = 0;
        for (char c : word) {
            s ^= 1 << (c - 'a');
            r += res[s]++;
            for (int i = 1; i <= 512; i <<= 1) {
                r += res[s ^ i];
            }
        }
        return r;
    }
};