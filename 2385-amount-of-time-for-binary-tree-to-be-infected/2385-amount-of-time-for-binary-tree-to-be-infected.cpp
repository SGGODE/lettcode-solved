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
    int time(vector<int>adj[],int node){
        queue<pair<int,int>>pq;
        pq.push({node,0});
        vector<bool>vis(1e5+1,0);
        vis[node]=1;
        int maxtime = 0;
        while(!pq.empty()){
            int cnode = pq.front().first;
            int time = pq.front().second;
            pq.pop();
            maxtime = max(maxtime,time);
            for(auto&it:adj[cnode]){
                if(!vis[it]){
                    vis[it]=1;
                    pq.push({it,time+1});
                }
            }
        }
        return maxtime;
    }
    void Convertthetree(TreeNode* root,vector<int>adj[]){
       // if(root==NULL)return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            Convertthetree(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            Convertthetree(root->right,adj);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<int>adj[100001];
        Convertthetree(root,adj);
        return time(adj,start);
    }
};