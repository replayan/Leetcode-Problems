class Solution {
    /**
     * @param Integer[] $score
     * @return String[]
     */
    function findRelativeRanks($score) {
        $sortedIndices = range(0, count($score) - 1);
        $scoreIndexMap = array_combine($score, range(0, count($score) - 1));

        usort($sortedIndices, function($a, $b) use ($score) {
            return $score[$b] - $score[$a];
        });

        $result = array_fill(0, count($score), "");

        foreach ($sortedIndices as $i => $index) {
            if ($i == 0)
                $result[$index] = "Gold Medal";
            elseif ($i == 1)
                $result[$index] = "Silver Medal";
            elseif ($i == 2)
                $result[$index] = "Bronze Medal";
            else
                $result[$index] = (string)($i + 1);
        }
        return $result;
    }
}
