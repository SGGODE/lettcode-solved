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
    TreeNode* temp;
    void find(TreeNode* root,int val){
         if(root==NULL)return;
        if(root->val==val){
            temp=root;
            return;
        }
        if(root->val>val){
           find(root->left,val);
        }
        if(root->val<val){
            find(root->right,val);
        }
      //  return NULL;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       find(root,val);
        return temp;
    }
};