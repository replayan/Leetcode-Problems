/* xor method:->
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(char c:t){
            res^=c;
        }
        for(char c:s){
            res^=c;
        }
        return res;
    }
};
*/ 
// sum of two method:-> 

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumOfS=0, sumOfT=0;
        for(char c:s){
            sumOfS+=c;
        }
        for(char c:t){
            sumOfT+=c;
        }
        return static_cast<char>(sumOfT-sumOfS); // ascii to char 
    }
};