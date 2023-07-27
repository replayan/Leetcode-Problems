// Hashtable

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> encounteredNumbers;

        while (n != 1 && !encounteredNumbers.count(n)) {
            encounteredNumbers.insert(n);

            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
