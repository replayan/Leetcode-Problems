
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;

        int minOps = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            // Collect values of the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Calculate minimum swaps needed to sort this level
            minOps += calculateMinSwaps(levelValues);
        }

        return minOps;
    }

private:
    int calculateMinSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> indexedArr(n);
        for (int i = 0; i < n; ++i) {
            indexedArr[i] = {arr[i], i};
        }

        // Sort the array by value while keeping track of original indices
        sort(indexedArr.begin(), indexedArr.end());
        vector<bool> visited(n, false);

        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position, skip
            if (visited[i] || indexedArr[i].second == i)
                continue;

            // Find cycle size
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;
                ++cycleSize;
            }

            // Add (cycleSize - 1) to swaps
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
