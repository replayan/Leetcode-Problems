class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        long long int mask = 1;
        long long int temp = n;

        while (temp > 0) {
            mask <<= 1;
            temp >>= 1;
        }
        mask -= 1;
        // one's complement
        int complement = n ^ mask;
        return complement;
    }
};