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
   bool issame(TreeNode* p,TreeNode* q){
       if(p==NULL&&q==NULL)return 1;
       if(p->right!=NULL&&q->right!=NULL){
           if(p->right->val==q->right->val)issame(p->right,q->right);
           else return 0;
       }
       if(p->left!=NULL&&q->left!=NULL){
           if(p->left->val==q->left->val)issame(p->left,q->left);
           else return 0;
       }
       if(!p->right&&q->right)return 0;
        if(!p->left&&q->left)return 0;
        if(p->right&&!q->right)return 0;
        return 0;
   }
   void preorder(TreeNode* root,vector<int>&v){
       if(root==NULL){
          // v.push_back(0);
           return;
       }
       v.push_back(root->val);
       if(root->left)preorder(root->left,v);
       if(!root->left)v.push_back(0);
       if(root->right)preorder(root->right,v);
        if(!root->right)v.push_back(0);
   }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v,x;
        preorder(p,v);
        preorder(q,x);
        for(auto it:v)cout<<it<<" ";
        cout<<endl;
        return v==x;
//         if(p->val!=q->val)return 0;
//        // if(p->val==q->val)return 1;
//        // else{
           
//             return isSameTree(p->right,q->right)&&isSameTree(p->left,q->left);
//        // }
//       // return issame(p,q);
    }
};