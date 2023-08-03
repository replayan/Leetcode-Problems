class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result;
        vector<string> mapping = {
            "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        queue<string> q;
        q.push("");

        for (int i = 0; i < digits.length(); i++) {
            int digit = digits[i] - '0';
            const string& letters = mapping[digit];
            int qSize = q.size();

            for (int j = 0; j < qSize; j++) {
                string current = q.front();
                q.pop();

                for (char c : letters) {
                    q.push(current + c);
                }
            }
        }

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
