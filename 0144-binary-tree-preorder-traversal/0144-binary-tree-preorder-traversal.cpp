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
    void preorder(vector<int>&v,TreeNode* root){
        if(root==NULL)return;
        v.push_back(root->val);
        preorder(v,root->left);
        preorder(v,root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(v,root);
        return v;
    }
};