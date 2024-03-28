function maxSubarrayLength(nums: number[], k: number): number {
    let ans = 0;
    const first_occur: Map<number, number[]> = new Map();
    const n = nums.length;
    for (let i = 0, j = 0; j < n; j++) {
        if (!first_occur.has(nums[j])) {
            first_occur.set(nums[j], []);
        }
        first_occur.get(nums[j])!.push(j);
        if (first_occur.get(nums[j])!.length === k + 1) {
            if (first_occur.get(nums[j])![0] >= i) {
                i = first_occur.get(nums[j])![0] + 1;
            }
            first_occur.get(nums[j])!.shift();
        }
        ans = Math.max(ans, j - i + 1);
    }
    return ans;
}