// Boyer moore String match algorithm

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) {
            return 0;
        }
        if (haystackLen < needleLen) {
            return -1;
        }

        vector<int> badChar(256, needleLen); 

        for (int i = 0; i < needleLen - 1; ++i) {
            badChar[needle[i]] = needleLen - 1 - i;
        }

        int i = needleLen - 1;
        int j = needleLen - 1;

        while (i < haystackLen) {
            if (haystack[i] == needle[j]) {
                if (j == 0) {
                    return i; 
                }
                --i;
                --j;
            } else {
                i += max(1, needleLen - j);  
                j = needleLen - 1;
            }
        }
        return -1; 
    }
};
