class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Finding the total sum of chalks and calculate the remainder of k
        long long totalSum = 0;
        for (int amount : chalk) {
            totalSum += amount;
        }
        k %= totalSum;
        // Iterating over the chalk array to find the student who can't finish their chalk
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};
