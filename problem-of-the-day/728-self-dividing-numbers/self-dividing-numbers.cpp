class Solution {
public:
    bool isSelfDiv(int num){
        string res=to_string(num);
        for (char digitChar : res) {
            int digit=digitChar-'0';
            if (digit==0 || num%digit != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; ++i){
            if(isSelfDiv(i)){
                res.push_back(i);
                // break;
            }
        }
        return res;
    }
};