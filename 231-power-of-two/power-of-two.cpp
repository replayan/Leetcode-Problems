// 1. The first condition `(n >= 1)` ensures that `n` is a positive integer. We want to exclude zero and negative numbers because they cannot be powers of two. If `n` is less than 1, it means it's either zero or negative, and we return `false`.

// 2. The second condition `!(n & (n - 1))` checks if `n` has only one bit set to 1. This is the crucial part of the logic to determine if `n` is a power of two. Here's how it works:

//    - When we subtract 1 from a power of two, the result will have all the bits set to 1 except for the bit that was originally set to 1 in the power of two. For example, if `n` is 8 (which is 2^3), subtracting 1 gives us 7 (which is 2^3 - 1). In binary representation, 8 is `1000` and 7 is `0111`. Notice that all the bits except the leftmost bit are set to 1 in 7.
   
//    - The bitwise AND operation `n & (n - 1)` compares the bits of `n` and `(n - 1)`. If `n` has only one bit set to 1, the result of this operation will be 0. This is because the corresponding bits in `n` and `(n - 1)` will be different for that particular bit, resulting in a 0 in the AND operation. For example, if `n` is 8 and `(n - 1)` is 7, the bitwise AND operation `8 & 7` will give us 0, indicating that `n` is a power of two.
   
//    - The `!` operator is used to negate the result of the bitwise AND operation. So if the result is 0 (indicating that `n` is a power of two), `!(n & (n - 1))` will be `true`. If the result is non-zero (indicating that `n` is not a power of two), `!(n & (n - 1))` will be `false`.

// 3. Finally, the function returns the result of the combined conditions `(n >= 1 && !(n & (n - 1)))`. If `n` is a positive integer and has only one bit set to 1, the function returns `true`, indicating that `n` is a power of two. Otherwise, it returns `false`.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>=1&&!(n&(n-1)));
    }
};