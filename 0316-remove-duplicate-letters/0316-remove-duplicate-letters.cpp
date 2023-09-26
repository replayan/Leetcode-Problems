/*
1. Create an array to check if a character is already in the result.
2. Create an array to store the last occurrence index of each character.
3. Populate the last occurrence index array.
4. Iterate through the string to build the result.
5. Skip characters already in the result.
6. Remove characters from the end of the result that are greater and still appear later in the string.
7. Add the current character to the result.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        bool inResult[26] = {false};
        int lastOccurrence[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];
            if (inResult[currentChar - 'a']) {
                continue;
            }
            while (!result.empty() && currentChar < result.back() && i < lastOccurrence[result.back() - 'a']) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += currentChar;
            inResult[currentChar - 'a'] = true;
        }
        return result;
    }
};
