bool isIsomorphic(char* s, char* t) {
    int mp1[256] = {0};
    int mp2[256] = {0};
    int i = 0;
    for (; s[i] != '\0' && t[i] != '\0'; ++i) {
        int c1 = s[i];
        int c2 = t[i];

        // If neither character is mapped yet
        if (mp1[c1] == 0 && mp2[c2] == 0) {
            mp1[c1] = c2 + 1;  // Map c1 to c2 in mp1
            mp2[c2] = c1 + 1;  // Map c2 to c1 in mp2
        }
        // If the mapping is invalid
        else if (mp1[c1] != c2 + 1 || mp2[c2] != c1 + 1) {
            return false;  // Strings are not isomorphic
        }
    }
    return s[i] == '\0' && t[i] == '\0';  // Strings are isomorphic
}