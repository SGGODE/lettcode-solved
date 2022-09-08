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
    void inorder(TreeNode* root,vector<int>&v){
       if(root==NULL){
          return;
       }
        if(root->left){
            inorder(root->left,v);
        }
        v.push_back(root->val);
         if(root->right){
            inorder(root->right,v);
        } 
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return v;
    }
};