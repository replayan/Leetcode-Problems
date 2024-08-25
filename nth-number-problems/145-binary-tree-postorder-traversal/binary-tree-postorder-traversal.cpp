class Solution {
public:
    void postorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        // Recurse on the left subtree
        postorder(node->left, result);
        
        // Recurse on the right subtree
        postorder(node->right, result);
        
        // Visit the root node
        result.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
