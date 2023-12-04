class Solution {
public:
    string largestGoodInteger(string num) {
        string ss[]={"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
        string largeSequence="";
        for(int i=0; i<=num.size()-3; ++i){
            string str=num.substr(i,3);
            for(const string& sequence:ss){
                if(str==sequence && str>largeSequence){
                    largeSequence=str;
                }
            }
        }
        return largeSequence;
    }
};