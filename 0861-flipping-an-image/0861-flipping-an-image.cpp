class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row : image) {
            for (int i = 0; i < (row.size() + 1) / 2; i++) {
                int temp = row[i] ^ 1;
                row[i] = row[row.size() - i - 1] ^ 1;
                row[row.size() - i - 1] = temp;
            }
        }
        return image;
    }
};
