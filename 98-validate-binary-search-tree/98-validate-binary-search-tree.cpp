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
    void check(vector<int> &v,TreeNode* root){
         if(root==NULL)
          return;
         check(v,root->left);
         v.push_back(root->val);
         check(v,root->right);
     }
public:
    bool isValidBST(TreeNode* root) {
       vector<int> v;
        check(v,root);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])
                return 0;
        }
       return 1;
    }
};