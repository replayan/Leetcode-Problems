class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        // potential substring lengths
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string substring = s.substr(0, len);
                string repeated = "";
                
                // make a repeated string of length n
                for (int i = 0; i < n / len; i++) {
                    repeated += substring;
                }
                
                if (repeated == s) {
                    return true;
                }
            }
        }  
        return false;
    }
};
