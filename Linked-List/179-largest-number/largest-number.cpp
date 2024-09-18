class Solution {
public:
    static bool compare(const string &a, const string &b) {
        // Customized comparator: return true if a + b > b + a
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        
        sort(numStrings.begin(), numStrings.end(), compare);
        if (numStrings[0] == "0") {
            return "0";
        }
        
        string result;
        for (const string &numStr : numStrings) {
            result += numStr;
        }
        return result;
    }
};
