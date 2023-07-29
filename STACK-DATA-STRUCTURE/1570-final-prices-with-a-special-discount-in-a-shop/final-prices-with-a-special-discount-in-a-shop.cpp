class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);
        stack<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && prices[i] <= prices[stack.top()]) {
                result[stack.top()] = prices[stack.top()] - prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            result[stack.top()] = prices[stack.top()];
            stack.pop();
        }
        return result;
    }
};
