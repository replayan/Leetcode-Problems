class Solution {
public:
    bool isPalindrome(string s) {
        string removeSentence;
        for(char c:s){
            if(isalnum(c)){
                removeSentence+=c;
            }
        }
        for(char &c:removeSentence){
            c=tolower(c);
        }
        int left=0;
        int right=removeSentence.size()-1;
        while(left<right){
            if(removeSentence[left]!=removeSentence[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};