class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves=0;
        while(target && maxDoubles){
            if(target%2){
                target--;
            }else{
                target/=2;
                maxDoubles--;
            }
            moves+=1;
        }
        return moves+target-1;
    }
};