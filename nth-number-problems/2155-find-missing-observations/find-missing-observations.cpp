class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        int sum = (m + n) * mean - n;
        for (int x : rolls) {
            sum -= x;
        }
        if (sum < 0) {
            return {};
        }
        const int num = sum / 5;
        if (num > n) {
            return {};
        }
        vector<int> r(n, 1);
        for (int i = 0; i < num; ++i) {
            r[i] = 6;
        }
        if ((r.back() += sum % 5) > 6) {
            return {};
        }
        return r;
    }
};