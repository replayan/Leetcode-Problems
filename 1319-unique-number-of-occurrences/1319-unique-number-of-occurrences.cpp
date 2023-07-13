class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> frequencyMap;
        
        for (int i = 0; i < arr.size(); i++) {
            frequencyMap[arr[i]]++;
        }
        
        std::unordered_set<int> uniqueFrequencies;
        
        for (const auto& pair : frequencyMap) {
            if (!uniqueFrequencies.insert(pair.second).second) {
                return false;
            }
        }
        return true;   
    }
};