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
    void sub(TreeNode* root,string&res){
        if(root==NULL){
            res.push_back(')');
            return;
        }
        res.push_back(root->val+'0');
        cout<<root->val<<" "<<res<<endl;
        if(root->left==NULL&&root->right==NULL){
             res.push_back(')');
           // return;
        }
        if(root->left!=NULL){
            res.push_back('(');
            sub(root->left,res);
        }else{
            res.push_back('()');
         //   return;
        }
        if(root->right!=NULL){
            res.push_back('(');
            sub(root->right,res);
        }else{
             res.push_back(')');
        }
    }
public:
    string tree2str(TreeNode* root) {
        if(root==NULL)return "";
        string s = to_string(root->val);
        if(root->left) s+= "("+tree2str(root->left)+")";
        else if (root->right) s += "()";
        if(root->right) s+= "("+tree2str(root->right)+")";
        return s;
    }
};