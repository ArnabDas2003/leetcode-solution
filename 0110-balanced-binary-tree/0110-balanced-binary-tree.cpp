class Solution {
public:
    // Helper function: returns height if balanced, else -1
    int check(TreeNode* root) {
        if (root == NULL) return 0;

        int left = check(root->left);
        if (left == -1) return -1;  // left subtree not balanced

        int right = check(root->right);
        if (right == -1) return -1; // right subtree not balanced

        if (abs(left - right) > 1) return -1; // current node not balanced

        return 1 + max(left, right); // height of current subtree
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
