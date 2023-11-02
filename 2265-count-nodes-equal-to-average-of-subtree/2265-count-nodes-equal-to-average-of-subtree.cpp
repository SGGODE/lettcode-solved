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
    int cnt = 0;
    vector<pair<pair<int,int>,int>>pq;
    void size(TreeNode* root,int&nodes){
        if(root==NULL)return;
        ++nodes;
        size(root->left,nodes);
        size(root->right,nodes);
    }
    void Sum(TreeNode* root,int&sum){
        if(root==NULL)return;
        sum+=root->val;
        Sum(root->left,sum);
        Sum(root->right,sum);
    }
    void sub(TreeNode* root){
        if(root==NULL)return;
        int sum = 0;
        Sum(root,sum);
        int len = 0;
        size(root,len);
        int temp = sum/len;
        if(temp==root->val)++cnt;
        sub(root->left);
        sub(root->right);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        sub(root);
        return cnt;
    }
};