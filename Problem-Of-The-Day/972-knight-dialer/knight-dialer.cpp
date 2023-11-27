class Solution {
public:
    int knightDialer(int N) {
        long long x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, x6 = 1, x7 = 1, x8 = 1, x9 = 1, x0 = 1;
        for (int i = 1; i < N; ++i) {
            long long temp1 = (x6 + x8) % (1000000007);
            long long temp2 = (x7 + x9) % (1000000007);
            long long temp3 = (x4 + x8) % (1000000007);
            long long temp4 = (x3 + x9 + x0) % (1000000007);
            long long temp5 = 0;
            long long temp6 = (x1 + x7 + x0) % (1000000007);
            long long temp7 = (x2 + x6) % (1000000007);
            long long temp8 = (x1 + x3) % (1000000007);
            long long temp9 = (x2 + x4) % (1000000007);
            long long temp0 = (x4 + x6) % (1000000007);
            x1 = temp1;
            x2 = temp2;
            x3 = temp3;
            x4 = temp4;
            x5 = temp5;
            x6 = temp6;
            x7 = temp7;
            x8 = temp8;
            x9 = temp9;
            x0 = temp0;
        }
        return (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x0) % (1000000007);
    }
};
