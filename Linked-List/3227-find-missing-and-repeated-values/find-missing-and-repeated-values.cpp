class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n; // The expected range of numbers is [1, N]
        unordered_set<int> seen;
        int a = -1, b = -1;

        // Step 1: Find the repeating number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                if (seen.count(num))
                    a = num; // Found duplicate
                seen.insert(num);
            }
        }

        // Step 2: Find the missing number
        for (int i = 1; i <= N; i++) {
            if (!seen.count(i)) {
                b = i; // Missing number found
                break;
            }
        }

        return {a, b};
    }
};
