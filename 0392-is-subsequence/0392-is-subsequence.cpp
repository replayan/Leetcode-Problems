class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,x=s.size(),y=t.size();
        while(i<x && j<y){
            if(s[i]==t[j]){
                i++;
                j++;
            } else{
                j++;
            }
        }
        return i==x;
    }
};