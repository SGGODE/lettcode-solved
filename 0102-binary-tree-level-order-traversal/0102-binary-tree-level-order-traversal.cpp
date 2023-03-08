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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
          return v;
       vector<int> x;
        queue<TreeNode*> pq;
        pq.push(root);
        TreeNode* temp=new TreeNode(10001);
        pq.push(temp);
      // x.push_back(root->val);
      // v.push_back(x);
       //x.clear();
       /*while(root->left!=NULL||root->right!=NULL){
           x.push_back(root->left->val);
           x.push_back(root->right->val);
           v.push_back(x);
           x.clear();
         if(root->left->left!=NULL||root->left->right!=NULL)  
             levelOrder(root->left);
        levelOrder(root->right);
       }*/
       //  while(!q.empty()){
       //     int n=q.size();
       //     for(int i=1;i<=n;i++){
       //         TreeNode* temp=q.front();
       //         if(temp->left)
       //          q.push(temp->left);
       //         if(temp->right)
       //          q.push(temp->right);
       //         q.pop();
       //         x.push_back(temp->val);
       //     }
       //   v.push_back(x);
       //  x.clear();
       // }
        while(!pq.empty()){
            TreeNode* curr=pq.front();
            pq.pop();bool flag=0;
            if(pq.front()==temp){
                pq.pop();flag=1;
            }
            x.push_back(curr->val);
            if(curr->left){
                pq.push(curr->left);
            }
            if(curr->right){
                pq.push(curr->right);
            }
            if(flag){
                pq.push(temp);
                v.push_back(x);
                x.clear();
            }
        }
        return v;
    }
};