class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function getSumAbsoluteDifferences($nums) {
        $n = count($nums);
        $ans = array_fill(0, $n, 0);
        for ($i = 1; $i < $n; $i++) {
            $ans[0] += ($nums[$i] - $nums[0]);
        }
        for ($j = 1; $j < $n; $j++) {
            $ans[$j] = $ans[$j - 1] + ($nums[$j] - $nums[$j - 1]) * $j - ($nums[$j] - $nums[$j - 1]) * ($n - $j);
        }
        return $ans;
    }
}
