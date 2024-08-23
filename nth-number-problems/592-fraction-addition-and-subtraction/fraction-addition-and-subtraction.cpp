class Solution {
public:
    string fractionAddition(string expression) {
        istringstream ss(expression);
        int num = 0, denom = 1, n, d;
        char slash, sign;
        
        while (ss >> n >> slash >> d) {
            num = num * d + n * denom;
            denom *= d;
            int g = gcd(abs(num), abs(denom));
            num /= g;
            denom /= g;
        }
        return to_string(num) + "/" + to_string(denom);
    }
};