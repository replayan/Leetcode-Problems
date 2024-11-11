class Solution {
    bool isPrime(int x) {
        if (x == 1) {
            return false;
        }
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        int p = 0;
        for (int x : nums) {
            if (x <= p) {
                return false;
            }
            bool mark = false;
            for (int i = x - p - 1; i > 0; --i) {
                if (isPrime(i)) {
                    p = x - i;
                    mark = true;
                    break;
                }
            }
            if (!mark) {
                p = x;
            }
        }
        return true;
    }
};