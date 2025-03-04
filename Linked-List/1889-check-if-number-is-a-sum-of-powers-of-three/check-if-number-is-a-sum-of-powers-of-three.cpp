class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2)
                return false; // if there's a '2' in base-3, return false
            n /= 3;           // moving to the next digit in base-3
        }
        return true;
    }
};
