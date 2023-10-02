class Solution {
public:
    bool winnerOfGame(string colors) {
        int ca=0, cb=0;
        for(int i=0; i<colors.length(); ++i){
            if(colors[i+1]==colors[i] && colors[i]==colors[i+2]){
                if(colors[i]=='A'){
                    ca++;
                } else{
                    cb++;
                }
            }
        }
        return ca>cb;
    }
};