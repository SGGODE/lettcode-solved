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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
      vector<vector<int>>v;
       queue<TreeNode*>pq;
       pq.push(root);
       TreeNode* jump=new TreeNode(101);
     //  jump=101;
       pq.push(jump);
       vector<int>curr;bool revers=0;
       while(!pq.empty()){
          TreeNode* temp=pq.front();
           pq.pop();bool flag=0;
           curr.push_back(temp->val);
           if(pq.front()==jump){
               if(revers){
                reverse(curr.begin(),curr.end());
                v.push_back(curr);
                revers=0;
               }else{
                  v.push_back(curr);
                   revers=1;
               }
               curr.clear();
               pq.pop();
               flag=1;
           }
           if(temp->left){
               pq.push(temp->left);
           }if(temp->right){
               pq.push(temp->right);
           }
           if(flag)pq.push(jump);
       }
        return v;
    }
};