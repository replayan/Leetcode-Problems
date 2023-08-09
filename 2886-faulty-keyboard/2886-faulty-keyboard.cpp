class Solution {
public:
    string finalString(const string &s) {
        deque<char> dq;
        bool flip = false;
        
        for (char ch : s) {
            if (ch == 'i') {
                flip = !flip;
            } else {
                if (flip) {
                    dq.push_front(ch);
                } else {
                    dq.push_back(ch);
                }
            }
        }
        string result;
        for (char ch : dq) {
            result += ch;
        }
        return flip ? string(rbegin(result), rend(result)) : result;
    }
};
