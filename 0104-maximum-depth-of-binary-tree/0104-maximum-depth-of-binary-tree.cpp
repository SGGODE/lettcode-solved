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
    int cnt=0;
    void height(TreeNode* root,int call){
        if(root==NULL){
            return;
        }cnt++;
        if(call==1){
            height(root->left,call);
            height(root->right,call);
        }
    }
public:
    int maxDepth(TreeNode* root) {
      if(root==NULL)return 0;
      int left=maxDepth(root->left);
      int right=maxDepth(root->right);
      return max(left,right)+1;
    }
};