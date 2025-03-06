class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            cout << "n: " << n << ", n % 3: " << (n % 3) << endl;
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
