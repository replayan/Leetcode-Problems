class Solution {
    int findNext(const string& s, int& i) {
        for (; i < s.length() && s[i] == '_'; ++i)
            ;
        return i;
    }

public:
    bool canChange(string start, string target) {
        for (int i = 0, j = 0, n = start.length();; ++i, ++j) {
            i = findNext(start, i);
            j = findNext(target, j);
            if (i >= n) {
                return j >= n;
            }
            if (j >= n || start[i] != target[j]) {
                return false;
            }
            if ((start[i] == 'L' && j > i) || (start[i] == 'R' && j < i)) {
                return false;
            }
        }
        return true;
    }
};