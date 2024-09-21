class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        
        for (int i = 0; i < n; i++) {
            result.push_back(current);
            
            // Try to go deeper in the lexicographical tree (i.e., current * 10)
            if (current * 10 <= n) {
                current *= 10;
            } else {
                // Increment current, if it's divisible by 10 we must backtrack
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;
                }
                current++;
            }
        }
        
        return result;
    }
};
