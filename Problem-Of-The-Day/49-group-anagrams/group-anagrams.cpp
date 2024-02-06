class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string to create its canonical form
            anagramMap[sortedStr].push_back(str); // Group anagrams with the same canonical form
        }
        
        vector<vector<string>> result;
        for (const auto& pair : anagramMap) {
            result.push_back(pair.second); // Push back the groups of anagrams
        }
        
        return result;
    }
};