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
    int infection(vector<int>adj[],int start){
        int time = 0;
        queue<pair<int,int>>pq;
        pq.push({start,time});
        vector<bool>vis(100001,0);
        vis[start]=1;
        while(!pq.empty()){
            int node = pq.front().first;
            int t = pq.front().second;
            pq.pop();
            time = max(time,t);
            for(auto&it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    pq.push({it,t+1});
                }
            }
        }
        return time;
    }
    void Graph(TreeNode* root,vector<int>adj[]){
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            Graph(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            Graph(root->right,adj);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<int>adj[100001];
        Graph(root,adj);
        return infection(adj,start);
    }
};