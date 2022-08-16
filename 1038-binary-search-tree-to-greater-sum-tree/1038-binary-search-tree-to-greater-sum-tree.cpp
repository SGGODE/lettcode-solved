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
    private:
    int curr_sum=0;
     void greatersum(TreeNode* root){
         if(root==NULL)
            return;
         if(root->right)
             greatersum(root->right);
          curr_sum=curr_sum+root->val;
         root->val=curr_sum;
         if(root->left)
             greatersum(root->left);
     }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
         greatersum(root);
        return root;
    }
};