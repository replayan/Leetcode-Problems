class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        long long int mask = 1;
        long long int temp = num;

        while (temp > 0) {
            mask <<= 1;
            temp >>= 1;
        }
        mask -= 1;
        // one's complement
        int complement = num ^ mask;
        return complement;
    }
};
