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
    void sub(TreeNode* root,map<int,int>&mp,int&res){
        if(root==NULL)return;
        for(auto&it:mp){
             res = max(res,abs(root->val-it.first));
        }
        mp[root->val]++;
        sub(root->left,mp,res);
        sub(root->right,mp,res);
        --mp[root->val];
        if(mp[root->val]==0)mp.erase(root->val);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
       // set<int>s;
        int res = 0;
        map<int,int>mp;
        sub(root,mp,res);
        return res;
    }
};