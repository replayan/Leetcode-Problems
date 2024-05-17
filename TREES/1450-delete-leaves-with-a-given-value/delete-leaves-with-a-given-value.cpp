class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // If root is null, just return null
        if (root == NULL) {
            return nullptr;
        }
        // Recursively call on left and right subtrees
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        // After returning from recursion, check if current node is a leaf with the target value
        if (!root->left && !root->right && root->val == target) {
            // If it is, delete it by returning nullptr
            return nullptr;
        }
        // Otherwise, return the current node
        return root;
    }
};
