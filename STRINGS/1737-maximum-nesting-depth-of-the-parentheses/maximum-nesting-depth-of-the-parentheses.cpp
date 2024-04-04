class Solution {
public:
    int maxDepth(string s) {
        /* without using stack DS SC => O(1)
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
        */

        // using stack DS SC => O(N)

        stack<int> st;
        int maxCounter = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                st.pop();
            }
            maxCounter = max(maxCounter, (int)st.size());
        }
        return maxCounter;
    }
};