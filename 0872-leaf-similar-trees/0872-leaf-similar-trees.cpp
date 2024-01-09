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
    void sub(TreeNode* root,vector<int>&leaf){
         if(root==NULL)return;
         if(!root->left&&!root->right)leaf.push_back(root->val);
         sub(root->left,leaf);
         sub(root->right,leaf);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seq1,seq2;
        sub(root1,seq1);
        sub(root2,seq2);
        return seq1==seq2;
    }
};