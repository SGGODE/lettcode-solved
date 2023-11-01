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
    void preorder(TreeNode* root,map<int,int>&dp){
        if(root==NULL)return;
        dp[root->val]++;
        preorder(root->left,dp);
        preorder(root->right,dp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        preorder(root,mp);
        vector<int>res;
        int high = 0;
        for(auto&it:mp){
            high = max(high,it.second);
        }
        for(auto&it:mp){
            if(it.second==high)res.push_back(it.first);
        }
        return res;
    }
};