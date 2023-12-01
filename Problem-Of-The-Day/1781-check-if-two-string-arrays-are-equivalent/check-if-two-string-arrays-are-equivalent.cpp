class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1,res2;
        for(const string &str:word1){
            res1+=str;
        }
        for(const string &str:word2){
            res2+=str;
        }
        return res1==res2;
    }
};