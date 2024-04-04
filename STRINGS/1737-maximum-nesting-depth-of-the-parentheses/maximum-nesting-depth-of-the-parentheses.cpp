class Solution {
public:
    int maxDepth(string s) {
        int counter = 0, maxCounter = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++counter;
            } else if (s[i] == ')') {
                --counter;
            }
            maxCounter = max(maxCounter, counter);
        }
        return maxCounter;
    }
};