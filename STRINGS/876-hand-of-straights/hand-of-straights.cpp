class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        int n = size(hand);
        if (n % groupSize) {
            return false;
        }
        for (int& handNum : hand) {
            mp[handNum]++;
        }
        while (!mp.empty()) {
            int curr = mp.begin()->first;
            for (int i = 0; i < groupSize; ++i) {
                if (mp[curr + i] == 0) {
                    return false;
                }
                mp[curr + i]--;
                if (mp[curr + i] < 1) {
                    mp.erase(curr + i);
                }
            }
        }
        return true;
    }
};