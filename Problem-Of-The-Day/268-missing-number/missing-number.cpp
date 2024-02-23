/* TC: O(n) SC: O(1) =>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            res += i - nums[i];
        }
        return res;
    }
};

*/
// XOR solution TC: O(n) SC: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};