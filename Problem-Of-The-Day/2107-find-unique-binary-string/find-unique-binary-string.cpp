class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string S = "";
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i][i]=='0') {
                S+='1';
            } else {
                S+='0';
            }
        }
        return S;
    }
};
