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
    int ans = 0;
    void sub(TreeNode* root){
        if(root==NULL)return;
        ans = max(ans,(hr(root->left)+hr(root->right)));
        sub(root->left);
        sub(root->right);
    }
    int hr(TreeNode* root){
        if(root==NULL)return 0;
        return max(1+hr(root->left),1+hr(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        sub(root);
        return ans;
    }
};