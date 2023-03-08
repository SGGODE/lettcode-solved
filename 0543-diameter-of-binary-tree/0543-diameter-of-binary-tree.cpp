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
    // void postorder(TreeNode* root,vector<int>&v){
    //     if(root==NULL)return;
    //     postorder(root->left,v);
    //     postorder(root->right,v);
    //     v.push_back(root->val);
    // }
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        // vector<int>v;
        // postorder(root,v);
        // int x=v.size();
        // return x-1;
        // return 1;
        int l1=diameterOfBinaryTree(root->left);
        int r1=diameterOfBinaryTree(root->right);
        int l=height(root->left);
        int r=height(root->right);
        return max(l1,max(r1,(l+r)));
    }
};