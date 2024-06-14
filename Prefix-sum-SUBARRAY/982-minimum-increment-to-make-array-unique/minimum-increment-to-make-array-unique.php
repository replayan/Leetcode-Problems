class Solution {
    function minIncrementForUnique($nums) {
        sort($nums); 
        $moves = 0;
        $prev = $nums[0];

        for ($i = 1; $i < count($nums); $i++) {
            if ($nums[$i] <= $prev) {
                $moves += ($prev + 1 - $nums[$i]);
                $nums[$i] = $prev + 1;
            }
            $prev = $nums[$i];
        }
        return $moves;
    }
}
