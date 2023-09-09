class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low; i<=high; ++i){
            if(symmetric(i)){
                count++;
            }
        }
        return count;
    }

    bool symmetric(int i){
        string numStr=to_string(i);
        int len=numStr.length(),leftHalf=0,rightHalf=0;
        if(len%2!=0){
            return false;
        }
        for(int i=0; i<len/2; ++i){ // cal upto mid digit
            leftHalf+=numStr[i]-'0'; // convert ch to int
            rightHalf+=numStr[len-i-1]-'0';
        }
        return leftHalf==rightHalf;
    }
};