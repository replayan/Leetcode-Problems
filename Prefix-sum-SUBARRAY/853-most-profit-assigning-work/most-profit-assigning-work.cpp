class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Step 1: Pair and sort jobs by difficulty
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int maxProfitForCurrentDifficulty = 0;
        int jobIndex = 0;
        
        // Step 2: Iterate through each worker
        for (int ability : worker) {
            // Update the maximum profit for the current worker's ability
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) {
                maxProfitForCurrentDifficulty = max(maxProfitForCurrentDifficulty, jobs[jobIndex].second);
                jobIndex++;
            }
            // Add the maximum profit the current worker can achieve to the total profit
            maxProfit += maxProfitForCurrentDifficulty;
        }
        return maxProfit;
    }
};