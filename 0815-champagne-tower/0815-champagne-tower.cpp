class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currRow(1, poured);
        for (int i = 0; i <= query_row; i++) {
            vector<double> nextRow(i + 2, 0); // for new level cham. glass
            for (int j = 0; j <= i; j++) {
                if (currRow[j] >= 1) {
                    // Calculate overflow and distribute it to adjacent glasses.
                    double overflow = (currRow[j] - 1) / 2.0;
                    nextRow[j] += overflow;      // Fill the left glass.
                    nextRow[j + 1] += overflow;  // Fill the right glass.
                    currRow[j] = 1;              // Current glass holds 1 cup of champagne.
                }
            }
            // Update the current row for the next iteration, except in the query row.
            if (i != query_row) {
                currRow = nextRow;
            }
        }
        // Return the champagne in the specified glass.
        return currRow[query_glass];
    }
};
