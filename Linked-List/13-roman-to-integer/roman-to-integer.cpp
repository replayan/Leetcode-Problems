class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        int prev_val = 0;
        for (int i = size(s) - 1; i >= 0; --i) {
            int curr_value = roman_map[s[i]];
            if (curr_value < prev_val)
                total -= curr_value; // Subtract if smaller than previous
            else
                total += curr_value; // Otherwise, add it
            prev_val = curr_value;
        }
        return total;
    }
};