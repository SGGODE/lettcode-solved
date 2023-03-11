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
    void preorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        preorder(root->left,v);
         v.push_back(root->val);
        preorder(root->right,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        preorder(root,v);
       // sort(v.begin(),v.end());
       // if(v.size())
        return v[k-1];
    }
};