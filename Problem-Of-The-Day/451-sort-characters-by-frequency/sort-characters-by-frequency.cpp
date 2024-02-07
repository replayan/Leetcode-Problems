class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freqMap[a] == freqMap[b]) {
                return a < b; // If frequencies are equal, sort alphabetically
            }
            return freqMap[a] > freqMap[b]; // Sort by frequency in decreasing order
        });
        
        return s;
    }
};
