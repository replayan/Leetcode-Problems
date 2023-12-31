class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstOccurrence;
        int maxLength = -1;
        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];
            if (firstOccurrence.find(currentChar) == firstOccurrence.end()) {
                // If the character is not in the map, store its first occurrence
                firstOccurrence[currentChar] = i;
            } else {
                // If the character is in the map, calculate the length and update maxLength
                int currentLength = i - firstOccurrence[currentChar] - 1;
                maxLength = max(maxLength, currentLength);
            }
        }
        return maxLength;
    }
};
