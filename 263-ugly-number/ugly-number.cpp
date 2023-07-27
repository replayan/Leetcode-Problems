class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        int divisors[] = {2, 3, 5};

        for (int i = 0; i < 3; i++) {
            while (num % divisors[i] == 0) {
                num /= divisors[i];
            }
        }
        return num == 1;
    }
};