class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> last(3, -1);
        const int n = garbage.size();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (char c : garbage[i]) {
                ++r;
                if (c == 'M') {
                    last[0] = i;
                } else if (c == 'P') {
                    last[1] = i;
                } else {
                    last[2] = i;
                }
            }
            
        }
        for (int i = 0, s = 0; i < n; ++i) {
            s += i ? travel[i - 1] : 0;
            if (i == last[0]) {
                r += s;
            }
            if (i == last[1]) {
                r += s;
            }
            if (i == last[2]) {
                r += s;
            }
        }
        return r;
        
    }
};