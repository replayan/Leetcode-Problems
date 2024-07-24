class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> pairs; 
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            string s = to_string(n);
            int mapped_n = 0;
            
            // Map the digits of the number
            for (char c : s) {
                mapped_n *= 10;
                mapped_n += mapping[c - '0'];
            }
            
            // Store the mapped number and original index
            pairs.emplace_back(mapped_n, i);
        }
        sort(pairs.begin(), pairs.end());

        vector<int> result;
        for (const auto& p : pairs) {
            result.push_back(nums[p.second]);
        }
        return result;
    }
};