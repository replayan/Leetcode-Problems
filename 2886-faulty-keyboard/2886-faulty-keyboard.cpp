class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for(auto c: s){
            if( c != 'i' ) ans += c;
            else reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};