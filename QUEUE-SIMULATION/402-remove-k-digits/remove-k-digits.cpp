class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        // Iterate through each character in the input string
        for (int i = 0; i < num.size(); ++i) {
            // While the temporary string is not empty, the last character in the temporary
            // string is greater than the current character, and we have digits left to remove
            while (!st.empty() && st.back() > num[i] && k > 0) {
                // Remove the last character from the temporary string
                st.pop_back();
                // Decrement k since we have removed a digit
                --k;
            }

            // If the temporary string is not empty or the current character is not '0'
            // (to avoid leading zeros)
            if (!st.empty() || num[i] != '0') {
                // Append the current character to the temporary string
                st.push_back(num[i]);
            }
        }

        // After iterating through the entire string, if there are still digits left to remove
        while (!st.empty() && k > 0) {
            // Remove the last character from the temporary string
            st.pop_back();
            // Decrement k since we have removed a digit
            --k;
        }

        // If the temporary string is empty (i.e., all digits were removed)
        if (st == "") {
            // Return "0" as the smallest possible number
            return "0";
        }

        // Return the temporary string, which now contains the smallest possible number
        return st;
    }
};