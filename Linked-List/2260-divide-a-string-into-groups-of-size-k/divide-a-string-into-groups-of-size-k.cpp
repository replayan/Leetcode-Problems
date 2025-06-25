class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> r;
        for (int i = 0; i < s.length(); i += k) {
            string temp = s.substr(i, k);
            if (temp.length() < k) {
                temp.append(string(k - temp.length(), fill));
            }
            r.push_back(temp);
        }
        return r;
    }
};