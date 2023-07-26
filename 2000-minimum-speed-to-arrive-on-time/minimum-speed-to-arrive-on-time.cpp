class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) {
            return -1; 
        }

        int left = 1;
        int right = 10000000;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            double timeTaken = 0.0;

            for (int i = 0; i < n - 1; i++) {
                timeTaken += ceil((double)dist[i] / mid);
            }
            timeTaken += (double)dist[n - 1] / mid;

            if (timeTaken <= hour) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
