class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int digit = 1; digit <= 9; ++digit) {
            int num = digit;

            for (int nextDigit = digit + 1; nextDigit <= 9; ++nextDigit) {
                num = num * 10 + nextDigit;
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};