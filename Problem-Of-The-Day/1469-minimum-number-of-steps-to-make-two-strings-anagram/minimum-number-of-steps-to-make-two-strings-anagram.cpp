class Solution {
public:
    int minSteps(string source, string target) {
        // Create a vector to store the frequency of each character in the
        // target string
        vector<int> targetFreq(26, 0);

        // Count the frequency of each character in the target string
        for (char c : target) {
            ++targetFreq[c - 'a'];
        }

        // Initialize a variable to store the remaining unmatched characters
        int remainingUnmatched = target.size();

        // Iterate through each character in the source string
        for (char c : source) {
            // Get a reference to the frequency of the current character in the
            // target
            int& targetCharFreq = targetFreq[c - 'a'];

            // Check if there is a remaining occurrence of the current character
            // in the target
            if (targetCharFreq > 0) {
                // Match found, decrement the frequency in the target and reduce
                // the remaining unmatched count
                --targetCharFreq;
                --remainingUnmatched;
            }
        }
        // Return the count of remaining unmatched characters
        return remainingUnmatched;
    }
};
