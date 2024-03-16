class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> sumMap;
        sumMap[0] = -1;

        int maxLength = 0;
        int currSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            currSum += nums[i] ? 1 : -1; // Treat 1 as +1, and 0 as -1

            // If the current sum exists in the map,
            // it means we have seen this sum before
            if (sumMap.count(currSum)) {
                // Calculate the length of the balanced subarray
                int len = i - sumMap[currSum];
                maxLength = max(maxLength, len);
            }
            // If the current sum is encountered for the first time,
            // store it in the map with its index
            else {
                sumMap[currSum] = i;
            }
        }

        return maxLength;
    }
};