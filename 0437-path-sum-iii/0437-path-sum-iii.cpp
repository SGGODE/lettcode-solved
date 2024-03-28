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
    int sub(TreeNode* root,long long int pre,int target){
       if(root==NULL)return 0;
       long long int current = pre+root->val;
       return (current==target)+sub(root->left,current,target)+sub(root->right,current,target);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        return sub(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};