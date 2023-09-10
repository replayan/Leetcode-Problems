class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> stoneCount;
        int count = 0;
        for (char stone : stones) {
            stoneCount[stone]++;
        }
        for (char jewel : jewels) {
            if (stoneCount.count(jewel)) {
                count += stoneCount[jewel];
            }
        }
        return count;
    }
};
