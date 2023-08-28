class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++) { // COUNTING THE FREQ OF EACH ELEMENT
            int num = nums[i];
            frequency[num]++;
        }

        for (int i = 0; i < nums.size(); i++) { // CHECKING
            int num = nums[i];
            if (frequency[num] == 1) {
                return num;
            }
        }
        return -1;
    }
};
