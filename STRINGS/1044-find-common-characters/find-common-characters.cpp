class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, INT_MAX); // Initializing count vector with max int values

        // Iterating over each word in the words vector
        for (const string& word : words) {
            vector<int> curr_cnt(26, 0); // Current word character count

            // Counting the frequency of each character in the current word
            for (char c : word) {
                curr_cnt[c - 'a']++;
            }

            // Updating the cnt vector to hold the minimum frequency of each character
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], curr_cnt[i]);
            }
        }

        vector<string> res;

        // Constructing the result vector based on the counts in cnt
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                res.push_back(string(1, 'a' + i));
            }
        }

        return res;
    }
};
