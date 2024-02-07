/* class Solution {
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
*/
class Solution {
public:
    string frequencySort(string s) {
        string sortedString;
        int frequency[256] = {0}; 
        for (char c : s) {
            frequency[c]++;
        }
        while (true) {
            char maxChar = '\0';
            int maxFreq = 0;
            
            // Find the character with the maximum frequency
            for (int i = 0; i < 256; ++i) {
                if (frequency[i] > maxFreq) {
                    maxChar = (char)i;
                    maxFreq = frequency[i];
                }
            }
            // If max frequency is 0, all characters are sorted
            if (maxFreq == 0) {
                break;
            }
            // Append the character to the sorted string maxFreq times
            for (int i = 0; i < maxFreq; ++i) {
                sortedString.push_back(maxChar);
            }
            // Set the frequency of the character to 0 to mark it as processed
            frequency[maxChar] = 0;
        }
        return sortedString;
    }
};

