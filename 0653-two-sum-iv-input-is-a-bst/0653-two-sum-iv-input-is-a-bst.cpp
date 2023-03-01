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
        if(root==NULL)
            return;
        if(root->left)
            inorder(root->left,v);
        v.push_back(root->val);
        if(root->right)
            inorder(root->right,v);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]+v[j]==k)return 1;
            }
        }
        return 0;
    }
};