int numSteps(char* s) {
    int res = 0;
    int carry = 0;
    int length = strlen(s);

    for (int i = length - 1; i > 0; --i) {
        ++res;
        if ((s[i] - '0') + carry == 1) {
            carry = 1;
            ++res;
        }
    }
    return res + carry;
}