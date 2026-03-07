class Solution {
public:
    bool checkOnesSegment(string s) {
        while (!s.empty() && s.back() == '0') {
            s.pop_back();
        }
        return s.find('0') == string::npos;
    }
};