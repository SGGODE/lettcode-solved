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
    void diameter(TreeNode* root){
        if(root==NULL)return;
        ans = max(ans,(height(root->left)+height(root->right)));
        diameter(root->left);
        diameter(root->right);
    }
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return max(1+height(root->left),1+height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans;
    }
};