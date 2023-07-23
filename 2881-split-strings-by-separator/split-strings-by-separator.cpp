class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> st;
        for (int i = 0; i < words.size(); i++) {
            string currentWord;
            for (char c : words[i]) {
                if (c == separator) {
                    if (!currentWord.empty()) {
                        st.push_back(currentWord);
                        currentWord.clear();
                    }
                } else {
                    currentWord.push_back(c);
                }
            }
            if (!currentWord.empty()) {
                st.push_back(currentWord);
            }
        }
        return st;
    }
};