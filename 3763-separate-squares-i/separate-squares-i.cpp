class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // Helper function to calculate the below area for a given y_line
        auto calculateBelowArea = [&](double y_line) {
            double totalBelow = 0;
            for (const auto& square : squares) {
                int x = square[0], y = square[1], l = square[2];
                if (y_line > y + l) {  // Line is completely above this square
                    totalBelow += 1.0 * l * l;
                } else if (y_line > y) {  // Line cuts through this square
                    double heightBelow = y_line - y;
                    totalBelow += heightBelow * l;
                }
            }
            return totalBelow;
        };

        // Find the range for binary search
        double low = 1e9, high = 0;
        double totalArea = 0;
        for (const auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            low = min(low, static_cast<double>(y));
            high = max(high, static_cast<double>(y + l));
            totalArea += 1.0 * l * l;
        }

        // Binary search for y_line
        double precision = 1e-6;
        while (high - low > precision) {
            double mid = (low + high) / 2.0;
            double belowArea = calculateBelowArea(mid);
            if (belowArea * 2 < totalArea) {  // Line too low
                low = mid;
            } else {  // Line too high or perfect
                high = mid;
            }
        }

        return low;  // The result is within the precision range
    }
};