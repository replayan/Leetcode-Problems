class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Find the maximum frequency
        int maxFreq = 0;
        for (auto pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }

        // Iterate through the frequency map again, and add the frequencies of
        // elements that have the maximum frequency
        int totalFreq = 0;
        for (auto pair : freq) {
            if (pair.second == maxFreq) {
                totalFreq += pair.second;
            }
        }

        return totalFreq;
    }
};