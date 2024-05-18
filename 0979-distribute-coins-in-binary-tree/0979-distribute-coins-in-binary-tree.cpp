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
    
//     void Graph(TreeNode* root,vector<pair<int,int>>adj[],int node){
//         if(root->left){
//             adj[node].push_back({(2*node)+1,root->val});
//             adj[(2*node)+1].push_back({node,root->val});
//             Graph(root->left,adj,(2*node)+1);
//         }
//         if(root->right){
//             adj[node].push_back({(2*node)+2,root->val});
//             adj[(2*node)+2].push_back({node,root->val});
//             Graph(root->right,adj,(2*node)+2);
//         }
//     }
    int moves = 0;
    int sub(TreeNode*root){ 
        if(root==NULL)return 0;
        int ans = 0;
        int left = sub(root->left);
        int right = sub(root->right);
        moves+=(abs(left)+abs(right));
        return (root->val - 1)+(left+right);
    }
public:
    int distributeCoins(TreeNode* root) {
//         vector<pair<int,int>>adj[10001];
//         Graph(root,adj,0);
        sub(root);
        return moves;
    }
};