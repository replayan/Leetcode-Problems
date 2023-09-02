// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         for (vector<int>& row : image) {
//             for (int i = 0; i < (row.size() + 1) / 2; i++) {
//                 int temp = row[i] ^ 1;
//                 row[i] = row[row.size() - i - 1] ^ 1;
//                 row[row.size() - i - 1] = temp;
//             }
//         }
//         return image;
//     }
// };
// Two pointer :

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row : image) {
            int rowLength = row.size(); 
            int left = 0;
            int right = rowLength - 1;
            while (left <= right) {
                int temp = row[left] ^ 1;
                row[left] = row[right] ^ 1;
                row[right] = temp;
                left++;
                right--;
            }
        }
        return image;
    }
};
