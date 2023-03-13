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
    bool check(TreeNode* root0,TreeNode* root1){
       if(root0==NULL&&root1==NULL)return 1;
       if(!root0||!root1)return 0;
       // if(root0->left->val != root1->right->val)return 0;
       // if(root0->right->val!=root1->left->val)return 0;
      // if(root0->val!=root1->val)return 0;
       // check(root0->left,root1->right);
       // check(root0->right,root1->left);
       return (root0->val==root1->val)&&check(root0->left,root1->right)&&check(root0->right,root1->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
       return check(root->left,root->right);
    }
};