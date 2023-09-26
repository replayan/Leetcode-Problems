class Solution {
public:
    string smallestSubsequence(string s) {
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