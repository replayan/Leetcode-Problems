class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, reversed_s;

        while (ss >> word) {
            reverse(word.begin(), word.end());
            reversed_s += word + " ";
        }
        
        if (!reversed_s.empty()) {
            reversed_s.pop_back();
        }
        return reversed_s;
    }
};
