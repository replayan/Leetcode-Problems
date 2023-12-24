class Solution {
public:
    int minOperations(string s) {
        int cunt0=0, cunt1=0;
        for (int i=0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                cunt0+=(s[i] != '0');
                cunt1+=(s[i] != '1');
            } else {
                cunt0+=(s[i] != '1');
                cunt1+=(s[i] != '0');
            }
        }
        return min(cunt0, cunt1);
    }
};
