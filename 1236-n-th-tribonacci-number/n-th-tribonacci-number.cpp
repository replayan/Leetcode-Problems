class Solution {
public:
    int tribonacci(int n) {
        vector<int> t = {0, 1, 1};
        int i = 3;
        
        if (n < 3) {
            goto base_case;
        }
        
        loop:
        t.push_back(t[i - 1] + t[i - 2] + t[i - 3]);
        i++;
        if (i <= n) {
            goto loop;
        }
        
        base_case:
        return t[n];
    }
};
