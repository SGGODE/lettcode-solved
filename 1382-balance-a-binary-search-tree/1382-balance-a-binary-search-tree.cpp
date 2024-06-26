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
    void sub(TreeNode* root,vector<int>&inOrder){
        if(root==NULL)return;
        sub(root->left,inOrder);
        inOrder.push_back(root->val);
        sub(root->right,inOrder);
    }
    TreeNode* Tree(vector<int>&inOrder,int start,int end){
         if(start>end)return NULL;
         if(start==end){
             return new TreeNode(inOrder[end]);
         }
         int m = end < 2 ? end : (start+end)/2;
         TreeNode* root = new TreeNode(inOrder[m]);
         root->left = Tree(inOrder,start,m-1);
         root->right = Tree(inOrder,m+1,end);
         return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOrder;
        sub(root,inOrder);
        int n = inOrder.size();
        return Tree(inOrder,0,n-1);
    }
};