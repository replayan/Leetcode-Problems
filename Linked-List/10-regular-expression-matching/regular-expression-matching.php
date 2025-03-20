class Solution {
    function isMatch($s, $p) {
        if ($s === null || $p === null) {
            return false;
        }

        $dp = array_fill(0, strlen($s) + 1, array_fill(0, strlen($p) + 1, false));
        $dp[0][0] = true;

        for ($i = 0; $i < strlen($p); $i++) {
            if ($p[$i] === '*' && $dp[0][$i - 1]) {
                $dp[0][$i + 1] = true;
            }
        }

        for ($i = 0; $i < strlen($s); $i++) {
            for ($j = 0; $j < strlen($p); $j++) {
                if ($p[$j] === '.') {
                    $dp[$i + 1][$j + 1] = $dp[$i][$j];
                }
                if ($p[$j] === $s[$i]) {
                    $dp[$i + 1][$j + 1] = $dp[$i][$j];
                }
                if ($p[$j] === '*') {
                    if ($p[$j - 1] !== $s[$i] && $p[$j - 1] !== '.') {
                        $dp[$i + 1][$j + 1] = $dp[$i + 1][$j - 1];
                    } else {
                        $dp[$i + 1][$j + 1] = ($dp[$i + 1][$j] || $dp[$i][$j + 1] || $dp[$i + 1][$j - 1]);
                    }
                }
            }
        }

        return $dp[strlen($s)][strlen($p)];
    }
}