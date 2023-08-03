class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> res;
        for(int i=1; i<=n; i++){
            if(n % i == 0) 
                res.push_back(i);
        }
        if(k <= res.size()){
            return res[k-1];
        }
        return -1;
    }
};