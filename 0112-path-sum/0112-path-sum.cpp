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
bool flag=0;
// bool dfs(TreeNode* root,int target,int sum){
//       if(root==NULL){
//          // if(sum==target)return 1;
//           return 0;
//       }
//      sum+=root->val;
//       if(root->left==NULL&&root->right==NULL)
//       return (dfs(root->left,target,sum)||dfs(root->right,target,sum));
//       if(root->left==NULL&&root->right!=NULL)
//       return dfs(root->right,target,sum);
//       if(root->right==NULL&&root->left!=NULL)
//       return dfs(root->left,target,sum);
//    // return 1;
//        if(root->left==NULL&&root->right==NULL){
//           if(sum==target)return 1;
//        }
//    // return 0;
//   }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      //   if(root==NULL)return 0;
      //   if(root->left==NULL) return dfs(root->right,targetSum,root->val);
      //   if(root->right==NULL) return dfs(root->left,targetSum,root->val);
      // //  int sum=0;
      //   return dfs(root,targetSum,0);
        if(root==NULL)return 0;
        targetSum=targetSum-root->val;
        if(targetSum==0&&!root->right&&!root->left)return 1;
        return (hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum));
    }
};