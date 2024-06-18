class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        // Step 1: Pair and sort jobs by difficulty
        List<int[]> jobs = new ArrayList<>();
        for (int i = 0; i < difficulty.length; ++i) {
            jobs.add(new int[]{difficulty[i], profit[i]});
        }
        Collections.sort(jobs, (a, b) -> a[0] - b[0]);
        
        // Step 2: Sort workers by their ability
        Arrays.sort(worker);
        
        int maxProfit = 0;
        int maxProfitForCurrentDifficulty = 0;
        int jobIndex = 0;
        
        // Step 3: Iterate through each worker
        for (int ability : worker) {
            // Update the maximum profit for the current worker's ability
            while (jobIndex < jobs.size() && jobs.get(jobIndex)[0] <= ability) {
                maxProfitForCurrentDifficulty = Math.max(maxProfitForCurrentDifficulty, jobs.get(jobIndex)[1]);
                jobIndex++;
            }
            // Add the maximum profit the current worker can achieve to the total profit
            maxProfit += maxProfitForCurrentDifficulty;
        }
        
        return maxProfit;
    }
}