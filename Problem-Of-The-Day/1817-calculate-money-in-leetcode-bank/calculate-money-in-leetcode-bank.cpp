class Solution {
public:
    int totalMoney(int n) {
        int total=0;
        for (int d=0; d<n; ++d) {
            total += (d / 7 + 1) + (d % 7);
        }
        return total;        
    }
};