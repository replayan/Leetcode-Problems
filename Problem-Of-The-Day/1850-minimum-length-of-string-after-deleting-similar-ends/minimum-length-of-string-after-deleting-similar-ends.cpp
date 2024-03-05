class Solution {
public:
    int minimumLength(string s) {
        int r = s.length();
        for (int start = 0, end = r - 1; start < end && s[start] == s[end];) {
            const int temp = start;
            for (; start < end && s[start] == s[temp]; ++start)
                ;
            if (start == end) {
                return 0;
            }
            r -= start - temp;
            for (; s[end] == s[temp]; --end, --r)
                ;
        }
        return r;
    }
};