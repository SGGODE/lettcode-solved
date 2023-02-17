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
    void preorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        int min_diff=INT_MAX;
        int n=v.size();
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              int x=abs(v[i]-v[j]);
              if(min_diff>x){
                  min_diff=x;
              }
          }  
        }
        return min_diff;
    }
};