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
    int ans = 0;
    void sub(TreeNode* root,int number){
        if(root->left==NULL&&root->right==NULL){
            ans+=(number*10+root->val);
            return;
        }
        number = number*10 + root->val;
        if(root->left)sub(root->left,number);
        if(root->right)sub(root->right,number);
    }
public:
    int sumNumbers(TreeNode* root) {
        int number = 0;
        sub(root,number);
        return ans;
    }
};