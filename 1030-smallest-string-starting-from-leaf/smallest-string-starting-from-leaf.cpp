class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        // Call the solve function with an empty string as initial current value
        return solve(root, "");
    }

private:
    // Recursive helper function to traverse the tree and build the strings
    string solve(TreeNode* root, string current) {
        if (!root)
            return "";

        // Add the current node's value to the string
        current = char('a' + root->val) + current;

        // If the node has both left and right children
        if (root->left && root->right) {
            // Return the minimum of the results from left and right subtrees
            return min(solve(root->left, current), solve(root->right, current));
        }
        // If only left child exists
        if (root->left) {
            return solve(root->left, current);
        }
        // If only right child exists
        if (root->right) {
            return solve(root->right, current);
        }
        // If the node is a leaf node, return the formed string
        return current;
    }
};
