class Solution {
    function better(&$x, $y) {
        if ($x < 0 || $x > $y) {
            $x = $y;
        }
    }
    function minDifficulty($jobDifficulty, $d) {
        $n = count($jobDifficulty);
        $dp = array_fill(0, $d + 1, array_fill(0, $n + 1, -1));
        $dp[0][0] = 0;
        for ($i = 1; $i <= $d; ++$i) {
            for ($j = $i - 1; $j < $n; ++$j) {
                if ($dp[$i - 1][$j] >= 0) {
                    for ($c = -1, $k = $j; $k < $n; ++$k) {
                        $c = max($c, $jobDifficulty[$k]);
                        $this->better($dp[$i][$k + 1], $dp[$i - 1][$j] + $c);
                    }
                }
            }
        }
        return $dp[$d][$n];
    }
}
