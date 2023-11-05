class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int largest = arr[0];
        int consecutiveWins = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > largest) {
                largest = arr[i];
                consecutiveWins = 0;
            }
            consecutiveWins++;
            if (consecutiveWins == k) {
                break;
            }
        }
        return largest;
    }
};