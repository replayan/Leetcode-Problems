class Solution {
public:
    bool isPalindrome(string s) {
        string removeSentence;
        for(char c:s){ // remove commas,or any expressions like :,'
            if(isalnum(c)){
                removeSentence+=c;
            }
        }
        for(char &c:removeSentence){ // convert it to lowercase to avoid malfunction
            c=tolower(c);
        }
        int left=0;
        int right=removeSentence.size()-1;
        while(left<right){ // used two pointer technique to check first and last and then move
            if(removeSentence[left]!=removeSentence[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};