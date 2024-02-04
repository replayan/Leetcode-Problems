// \U0001f625\U0001f917☺\U0001f625\U0001f623\U0001f625

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.empty() || S.empty()) {
            return "";
        }
        vector<int> have;
        have.resize(256, 0);
        int non = 0;
        for (int i = 0; i < T.size(); ++i) {
            if (have[T[i]]-- == 0) {
                ++non;
            }
        }
        int left = 0, right = 0;
        string result;
        for (; right < S.size();) {
            for (; (right < S.size()) && non; ++right) {
                if (++have[S[right]] == 0) {
                    --non;
                }
            }
            if (non == 0) {
                for (;; ++left) {
                    if (have[S[left]] == 0) {
                        break;
                    }
                    --have[S[left]];
                }
                if ((result.empty()) || (result.size() > right - left)) {
                    result = S.substr(left, right - left);
                }
                --have[S[left++]];
                ++non;
            }
        }
        return result;
    }
};