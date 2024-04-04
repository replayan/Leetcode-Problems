int maxDepth(char* s) {
    int st[101];
    int top = -1;
    int maxCounter = 0;
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(') {
            st[++top] = i;
        } else if (s[i] == ')') {
            --top;
        }
        maxCounter = (top + 1 > maxCounter) ? top + 1 : maxCounter;
    }
    return maxCounter;
}
