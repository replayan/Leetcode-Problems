class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto impact = [](const pair<int, int>& a, const pair<int, int>& b) {
            double deltaA = ((double)(a.first + 1) / (a.second + 1)) -
                            ((double)a.first / a.second);
            double deltaB = ((double)(b.first + 1) / (b.second + 1)) -
                            ((double)b.first / b.second);
            return deltaA < deltaB;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(impact)>
            maxHeap(impact);

        for (const auto& cls : classes) {
            maxHeap.push({cls[0], cls[1]});
        }

        while (extraStudents--) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            maxHeap.push({pass + 1, total + 1});
        }

        double averageRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            averageRatio += (double)pass / total;
        }
        return averageRatio / classes.size();
    }
};
