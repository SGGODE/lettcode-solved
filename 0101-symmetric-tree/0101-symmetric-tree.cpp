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
    bool sub(TreeNode*root1,TreeNode*root2){
        if(root1==NULL&&root2==NULL)return 1;
        if((root1!=NULL&&root2==NULL)||(root1==NULL&&root2!=NULL))return 0;
        if(root1->val!=root2->val)return 0;
        //cout<<root1->val<<" "<<root2->val<<endl;
        return sub(root1->left,root2->right)&&sub(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return sub(root->left,root->right);
    }
};