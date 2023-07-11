/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int n=0;
    void num(TreeNode* root){
        if(root==NULL)return;
        ++n;
        if(root->left)num(root->left);
        if(root->right)num(root->right);
    }
    void make(TreeNode* root,vector<int>adj[]){
        if(root==NULL)return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            make(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            make(root->right,adj);
        }
    }
    void dfs(vector<int>&res,vector<int>adj[],vector<bool>&vis,int target,int k,int dist){
        vis[target]=1;
        if(dist==k)res.push_back(target);
        for(auto&it:adj[target]){
            if(!vis[it]&&dist<k){
                dfs(res,adj,vis,it,k,dist+1);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int tar=target->val;
        if(root==NULL)return {};
       // if(k==0)return {target};
        num(root);
        vector<int>adj[n+1];
        make(root,adj);
        vector<int>res;
        vector<bool>vis(n+1,0);
        dfs(res,adj,vis,tar,k,0);
        return res;
    }
};