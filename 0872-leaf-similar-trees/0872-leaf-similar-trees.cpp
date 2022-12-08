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
    void call(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        if(!root->right&&!root->left){
            v.push_back(root->val);
        }
        call(root->left,v);
        call(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        call(root1,v);
        vector<int>x;
        call(root2,x);
        //for(auto it:v)cout<<it<<" ";
        return x==v;
    }
};