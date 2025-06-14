/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   /* void helper(TreeNode* root, vector<int>& result) { 
      if (root == NULL) {
        return;
      }
      result.push_back(root->val);
      helper(root->left, result);
      helper(root->right, result);
    }*/
    /*vector<int> preorderTraversal(TreeNode* root) {
        /* vector<int> result;
         helper(root, result);
         return result;*/

        /* TreeNode* temp=root;
         while(temp->left!=NULL){
            preorder(temp->left);
            cout<<temp->val;
            return node;
         } 
         */
        vector<int> preorderTraversal(TreeNode* root) {
             vector<int> result;
             if (root == NULL) return result;

             stack<TreeNode*> st;
               st.push(root);

        while (!st.empty()) {
          TreeNode* node = st.top();
          st.pop();

          result.push_back(node->val); // Visit root first

        // Push right first so left is processed first
           if (node->right) st.push(node->right);
           if (node->left) st.push(node->left);
       }

        return result;
      }





         
    
};