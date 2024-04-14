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
    int result(TreeNode*root,bool flag){
        if(flag&&root->left==NULL&&root->right==NULL){
            return root->val;
        }
        int ans = 0;
        if(root->left!=NULL)ans += result(root->left,1);
        if(root->right!=NULL)ans += result(root->right,0);
        return ans;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = result(root,0);
        return sum;
    }
};