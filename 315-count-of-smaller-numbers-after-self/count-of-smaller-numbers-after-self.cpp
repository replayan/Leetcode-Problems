class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        vector<pair<int, int>> indexedNums; // A vector to store the pair (number, original index)

        // Create the vector with (number, original index) pairs
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }

        // Helper function to perform merge and count smaller elements
        function<void(int, int)> mergeAndCountSmaller = [&](int left, int right) {
            if (left >= right) {
                return;
            }

            int mid = left + (right - left) / 2;
            mergeAndCountSmaller(left, mid);
            mergeAndCountSmaller(mid + 1, right);

            // Merge the two sorted subarrays while counting the smaller elements
            vector<pair<int, int>> temp;
            int i = left; // Pointer for the left subarray
            int j = mid + 1; // Pointer for the right subarray
            int smallerCount = 0;

            while (i <= mid && j <= right) {
                if (indexedNums[i].first > indexedNums[j].first) {
                    temp.push_back(indexedNums[j++]);
                    ++smallerCount;
                } else {
                    // Update the count for elements on the left side that are greater than nums[j]
                    counts[indexedNums[i].second] += smallerCount;
                    temp.push_back(indexedNums[i++]);
                }
            }

            while (i <= mid) {
                // Update the count for elements on the left side that are greater than elements in the right subarray
                counts[indexedNums[i].second] += smallerCount;
                temp.push_back(indexedNums[i++]);
            }

            while (j <= right) {
                temp.push_back(indexedNums[j++]);
            }

            // Copy the merged and sorted elements back to the original indexedNums vector
            copy(temp.begin(), temp.end(), indexedNums.begin() + left);
        };

        // Perform merge sort and count smaller elements
        mergeAndCountSmaller(0, indexedNums.size() - 1);

        return counts;
    }
};
