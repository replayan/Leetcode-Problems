class Solution {
public:
    string defangIPaddr(string address) {
        string da;
        for(char c : address){
            if(c == '.'){
                da+="[.]";
            } else{
                da+=c;
            }
        }
        return da;
    }
};