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
    void call(TreeNode* &root,int val){
        root=new TreeNode(val);
    }
    void bst(TreeNode* &root,int&val){
       if(root==NULL)return;
        if(root->left==NULL&&root->val>val){
            call(root->left,val);
            return;
        }
         if(root->right==NULL&&root->val<val){
            call(root->right,val);
            return;
        }
       // if(root==NULL)return;
        if(root->val>val){
            bst(root->left,val);
        }
         if(root->val<val){
            bst(root->right,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        bst(root,val);
        return root;
    }
};