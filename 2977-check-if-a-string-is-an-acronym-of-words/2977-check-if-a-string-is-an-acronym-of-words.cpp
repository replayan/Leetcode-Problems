class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res="";
        for(int i=0; i<words.size(); i++){
            res.push_back(words[i][0]);
        }
        return res==s;
    }
};