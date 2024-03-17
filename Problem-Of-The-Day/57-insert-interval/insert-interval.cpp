class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> r;
        int i = 0;
        for (; i < intervals.size() && intervals[i][0] <= newInterval[0]; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                r.push_back(intervals[i]);
            } else {
                newInterval = {intervals[i][0], max(newInterval[1], intervals[i][1])};
            }
        }
        for (; i < intervals.size() && intervals[i][0] <= newInterval[1]; newInterval[1] = max(newInterval[1], intervals[i++][1]))
        ;
        r.push_back(newInterval);
        for (; i < intervals.size(); ++i) {
            r.push_back(intervals[i]);
        }
        return r;
    }
};