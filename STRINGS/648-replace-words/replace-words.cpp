class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots;
        for (const string& root : dictionary) {
            roots.insert(root);
        }

        istringstream iss(sentence);
        string word;
        string result = "";
        bool firstWord = true;

        while (iss >> word) {
            for (int i = 1; i <= word.size(); ++i) {
                string prefix = word.substr(0, i);
                if (roots.count(prefix)) {
                    word = prefix;
                    break;
                }
            }
            if (!firstWord) {
                result += " ";
            }
            result += word;
            firstWord = false;
        }

        return result;
    }
};
