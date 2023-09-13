class Solution {
public:
    int maximum69Number (int num) {
        string ss=to_string(num);
        for(char &i:ss){
            if(i=='6'){
                i='9';
                break;
            }
        }
        return stoi(ss);
    }
};