class Solution {
    function heightChecker($heights) {
        $clonedHeights = $heights;

        sort($clonedHeights);
        
        $count = 0;
        for ($i = 0; $i < count($heights); $i++) {
            if ($heights[$i] != $clonedHeights[$i]) {
                $count++;
            }
        }
        return $count;
    }
}
