int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return abs(a);
}
char* fractionAddition(char* expression) {
    int num = 0, denom = 1, n, d;
    char* result = (char*)malloc(32);
    char* p = expression;
    
    while (*p) {
        int sign = (*p == '-') ? -1 : 1;
        if (*p == '-' || *p == '+') p++; // Skip the sign if present

        n = sign * strtol(p, &p, 10);
        p++; // Skip the '/'
        d = strtol(p, &p, 10);
        
        num = num * d + n * denom;
        denom *= d;
        int g = gcd(abs(num), abs(denom));
        num /= g;
        denom /= g;
    }
    sprintf(result, "%d/%d", num, denom);
    return result;
}