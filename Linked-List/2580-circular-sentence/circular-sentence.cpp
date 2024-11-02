class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        // Spliting using spaces
        while (ss >> word) {
            words.push_back(word);
        }

        // Check each pair of consecutive words
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) {
                return false;
            }
        }

        // Check the circular condition: last word's last char == first word's
        // first char
        if (words.back().back() != words.front().front()) {
            return false;
        }

        return true;
    }
};
