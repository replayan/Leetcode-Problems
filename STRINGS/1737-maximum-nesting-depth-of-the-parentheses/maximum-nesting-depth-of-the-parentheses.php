class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function maxDepth($s) {
        $st = [];
        $maxCounter = 0;

        for ($i = 0; $i < strlen($s); $i++) {
            if ($s[$i] === '(') {
                array_push($st, $i);
            } else if ($s[$i] === ')') {
                array_pop($st);
            }
            $maxCounter = max($maxCounter, count($st));
        }

        return $maxCounter;
    }
}
