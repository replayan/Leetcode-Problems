class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int base_satisfied = 0, max_extra_satisfied = 0, current_extra_satisfied = 0;

        // Calculate the base satisfied customers (without using the grumpy trick)
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                base_satisfied += customers[i];
            }
        }

        // Calculate the maximum extra satisfied customers using the grumpy trick
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1) {
                current_extra_satisfied += customers[i];
            }
            if (i >= X) {
                if (grumpy[i - X] == 1) {
                    current_extra_satisfied -= customers[i - X];
                }
            }
            max_extra_satisfied = max(max_extra_satisfied, current_extra_satisfied);
        }

        return base_satisfied + max_extra_satisfied;
    }
};