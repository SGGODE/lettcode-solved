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
    int ans=INT_MIN;
    int sum(TreeNode* root){
      //  if(root==NULL)return 0;
         if(root==NULL)return 0;
        int left=sum(root->left);
        int right=sum(root->right);
        if(left<0)left=0;
        if(right<0)right=0;
        //cout<<left<<" "<<right<<endl;
        ans=max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
public:
    //int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
       sum(root);
        return ans;
    }
};