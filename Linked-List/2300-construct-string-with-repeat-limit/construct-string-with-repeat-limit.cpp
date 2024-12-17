class Solution {
    void make(string& r, char c, int num) {
        for (; num; --num, r.push_back(c))
            ;
    }

public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> v(26);
        for (char c : s) {
            ++v[c - 'a'];
        }
        string r;
        for (int num = 0, last = -1;;) {
            int i = 25;
            for (; i >= 0 && (v[i] == 0 || (last == i && num == repeatLimit));
                 --i)
                ;
            if (i < 0) {
                break;
            }
            if (i == last) {
                ++num;
            } else {
                last = i;
                num = 1;
            }
            --v[i];
            r.push_back(i + 'a');
        }
        return r;
    }
};