class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int inf = 1000000000;
        const int n = bloomDay.size();
        
        // Check if there are enough flowers to make m bouquets
        if (static_cast<long long>(m) * k > n) return -1;
        
        int left = 0, right = inf;
        
        // Binary search to find the minimum number of days
        while (left <= right) {
            int mid = left + (right - left) / 2; // Midpoint to check
            int bouquets = 0, flowers = 0;
            
            // Check how many bouquets can be made by mid days
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] <= mid) {
                    flowers++; // Count consecutive flowers
                    if (flowers == k) { // If we have enough flowers for one bouquet
                        bouquets++;
                        flowers = 0; // Reset the flower count
                    }
                } else {
                    flowers = 0; // Reset the flower count if the flower is not bloomed
                }
            }
            
            if (bouquets >= m) {
                right = mid - 1; // Try to find a smaller number of days
            } else {
                left = mid + 1; // Try to find a larger number of days
            }
        }
        
        return left > inf ? -1 : left; // Return the result
    }
};
