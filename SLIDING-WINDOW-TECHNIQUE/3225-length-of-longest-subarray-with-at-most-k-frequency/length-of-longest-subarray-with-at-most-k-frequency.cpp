class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, queue<int>> first_occur;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; r++) {
            // Push the current index into the queue for the current element
            first_occur[nums[r]].push(r);

            // If the frequency of the current element is k+1
            // (i.e., the size of the queue is k+1)
            if (first_occur[nums[r]].size() == k + 1) {
                // If the first occurrence of the current element is within the current window
                if (first_occur[nums[r]].front() >= l) {
                    // Update the left pointer to start from the next index
                    l = first_occur[nums[r]].front() + 1;
                }
                // Remove the oldest occurrence of the current element from the queue
                first_occur[nums[r]].pop();
            }
            // Update the maximum length of subarray with sum k
            ans = max(ans, r - l + 1);
        }
        // Returning the maximum length of subarray with sum k
        return ans;
    }
};