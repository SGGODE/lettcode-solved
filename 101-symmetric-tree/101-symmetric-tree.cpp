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
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1==NULL and root2==NULL){
            return 1;
        } 
        if(root1==NULL and root2!=NULL){
            return 0;
        }
        if(root1!=NULL and root2==NULL){
            return 0;
        }
        if(root1->val!=root2->val){
            return 0;
        }
        bool ch1=check(root1->left,root2->right);
        bool ch2=check(root1->right,root2->left);
        bool finaans=ch1 and ch2;
        return finaans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
       return check(root->left,root->right);
    }
};