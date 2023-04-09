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
    void order(TreeNode* root,vector<int>&v){
        if(root==NULL){
            v.push_back(1e8);
            return;
        }
        v.push_back(root->val);
        order(root->left,v);
        order(root->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       vector<int>v1;
       vector<int>v2;
        order(p,v1);
        order(q,v2);
        return v1==v2;
    }
};