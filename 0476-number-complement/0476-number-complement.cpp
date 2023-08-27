class Solution {
public:
    int findComplement(int num) {
        long long int res = 1;
        while (res <= num) {
            res *= 2;
        }
        return res - 1 - num;
    }
};