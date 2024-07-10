class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0, n = size(logs);
        for (auto i = 0; i < n; ++i) {
            if (logs[i] == "../") {
                ops = max(0, ops - 1);

            } else if (logs[i] != "./") {
                ops += 1;
            }
        }
        return ops;
    }
};