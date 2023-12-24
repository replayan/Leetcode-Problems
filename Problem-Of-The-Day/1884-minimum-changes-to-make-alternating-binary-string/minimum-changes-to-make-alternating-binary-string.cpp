class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count0 = 0, count1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') {
                    count0++;
                } else {
                    count1++;
                }
            } else {
                if (s[i] != '1') {
                    count0++;
                } else {
                    count1++;
                }
            }
        }
        return min(count0, count1);
    }
};
