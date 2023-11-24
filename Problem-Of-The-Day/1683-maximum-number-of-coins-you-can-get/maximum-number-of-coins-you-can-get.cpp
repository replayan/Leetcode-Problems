class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size(),result=0;
        for(int i=1; i<n-n/3; i+=2){
            result+=piles[i];
        }
        return result;
    }
};