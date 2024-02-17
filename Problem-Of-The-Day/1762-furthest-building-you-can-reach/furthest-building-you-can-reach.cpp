class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int i;
        for (i = 1; i < heights.size(); ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0) {
                if (bricks >= diff) {
                    bricks -= diff;
                    q.push(diff);
                } else if (ladders > 0) {
                    if (!q.empty() && diff < q.top()) {
                        bricks += q.top() - diff;
                        q.pop();
                        q.push(diff);
                    }
                    --ladders;
                } else {
                    break;
                }
            }
        }
        return i - 1;
    }
};
