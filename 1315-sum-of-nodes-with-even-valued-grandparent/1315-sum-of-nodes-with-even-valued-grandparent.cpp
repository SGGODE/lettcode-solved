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
    void preorder(TreeNode* root,queue<TreeNode*>&pq){
        if(root==NULL)return;
        if(root->val%2==0)pq.push(root);
        preorder(root->left,pq);
        preorder(root->right,pq);
    }
    void dfs(TreeNode* root,int&sum,int cnt){
        if(root==NULL)return;
        if(cnt==2){
            sum+=root->val;
            return;
        }
        dfs(root->left,sum,cnt+1);
         dfs(root->right,sum,cnt+1);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>pq;
        preorder(root,pq);
        int totalsum=0;
        while(!pq.empty()){
            int sum=0;
            TreeNode* temp=pq.front();
            pq.pop();
            dfs(temp,sum,0);
            totalsum+=sum;
        }
        return totalsum;
    }
};