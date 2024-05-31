class Solution {
    public function singleNumber($nums) {
        $res = [];
        $n = count($nums);
        for ($i = 0; $i < $n; ++$i) {
            $ifDuplicate = false;
            for ($j = 0; $j < $n; ++$j) {
                if ($i != $j && $nums[$i] == $nums[$j]) {
                    $ifDuplicate = true;
                    break;
                }
            }
            if (!$ifDuplicate) {
                $res[] = $nums[$i];
            }
        }
        return $res;
    }
}