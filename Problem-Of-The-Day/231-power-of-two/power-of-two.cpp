// Classic divide method tc : o(logN)
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n % 2 != 0) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};
*/
// bit wise ops :
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else
            return (n & (n - 1)) == 0;
    }
};
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else
            return ((1 << 30) % n) == 0;
    }
};