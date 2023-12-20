class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int low_choco=prices[0]+prices[1];
        for(int i=0; i<prices.size(); ++i){
            if(low_choco<=money){
                money-=low_choco;
                return money;
            }
        }
        return money;
    }
};