class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, queue<int>> first_occur;
        int n = nums.size();
        for (int i = 0, j = 0; j < n; ++j) {
            // Push the current index into the queue for the current element
            first_occur[nums[j]].push(j);

            // If the frequency of the current element is k+1
            // (i.e., the size of the queue is k+1)
            if (first_occur[nums[j]].size() == k + 1) {
                // If the first occurrence of the current element is within the current window
                if (first_occur[nums[j]].front() >= i) {
                    // Update the left pointer to start from the next index
                    i = first_occur[nums[j]].front() + 1;
                }
                // Remove the oldest occurrence of the current element from the queue
                first_occur[nums[j]].pop();
            }
            // Update the maximum length of subarray with sum k
            ans = max(ans, j - i + 1);
        }
        // Returning the maximum length of subarray with sum k
        return ans;
    }
};