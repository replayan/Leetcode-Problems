class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ss=s;
        for(int i=0;i<indices.size();i++){
            ss[indices[i]]=s[i];
        }
        return ss;
    }
};