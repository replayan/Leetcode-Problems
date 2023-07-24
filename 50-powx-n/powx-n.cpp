class Solution {
public:
    double myPow(double x, int n) {
        double y = static_cast<double>(n);
        double res = pow(x,y);
        return res;
    }
};