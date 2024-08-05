class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> have;
        for (const auto& s : arr) {
            ++have[s];
        }
        for (const auto& s : arr) {
            if (have[s] == 1 && --k == 0) {
                return s;
            }
        }
        return "";
        
    }
};