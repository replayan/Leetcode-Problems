class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        unordered_map<char, int> charCount;
        // Count the frequency of each character in chars
        for (char ch : chars) {
            charCount[ch]++;
        }
        // Check each word in words
        for (const string& word : words) {
            // Create a copy of the character count for comparison
            unordered_map<char, int> tempCharCount = charCount;
            bool isGood = true;
            // Check if the word can be formed using the characters in chars
            for (char ch : word) {
                if (tempCharCount[ch] > 0) {
                    tempCharCount[ch]--;
                } else {
                    isGood = false;
                    break;
                }
            }
            // If the word is good, add its length to the result
            if (isGood) {
                result += word.length();
            }
        }
        return result;
    }
};
