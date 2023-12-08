class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        const string current_value = to_string(root->val);
        const string left_subtree = tree2str(root->left);
        const string right_subtree = tree2str(root->right);
        if (right_subtree.length() > 0) {
            return current_value + "(" + left_subtree + ")(" + right_subtree + ")";
        } else if (left_subtree.length() > 0) {
            return current_value + "(" + left_subtree + ")";
        } else {
            return current_value;
        }
    }
};
