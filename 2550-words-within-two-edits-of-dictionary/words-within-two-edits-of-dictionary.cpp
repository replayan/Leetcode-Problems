class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> r;
        for (const auto& q : queries) {
            for (const auto& d : dictionary) {
                int t = 0;
                for (int i = 0; i < q.length() && t <= 2; ++i) {
                    if (d[i] != q[i]) {
                        ++t;
                    }
                }
                if (t <= 2) {
                    r.push_back(q);
                    break;
                }
            }
        }
        return r;
        
    }
};