class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> c;
        if (rowIndex < 0) {
            return c;
        }
        c.resize(rowIndex + 1);
        c[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            c[i] = 1;
            for (int j = i - 1; j > 0; --j) {
                c[j] += c[j - 1];
            } 
        }
        return c;
    }
};