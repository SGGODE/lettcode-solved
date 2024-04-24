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
    map<int,int>dp;
    void replace(TreeNode* root,int src,int dest,int node){
        if(root==NULL)return;
        if(root->val==src&&!dp.count(node)){
            dp[node]++;
            root->val = dest;
            return;
        }
        replace(root->left,src,dest,(node*2)+1);
        replace(root->right,src,dest,(node*2)+2);
    }
    void sub(TreeNode* root,vector<int>&res){
        if(root==NULL)return;
        sub(root->left,res);
        res.push_back(root->val);
        sub(root->right,res);
    }
public:
    void recoverTree(TreeNode* root) {
       vector<int>res;
       sub(root,res);
       int n = res.size();
       int j = n-1;
       int i = 0;
       // for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
       while(i<n-1){
           if(res[i]>res[i+1])break;
           i++;
       }
       while(j>0){
           if(res[j]<res[j-1])break;
           j--;
       }
       int src = res[i] , dest = res[j];
       replace(root,src,dest,0);
       replace(root,dest,src,0);
      //  cout<<src<<" "<<dest<<endl;
      // return root;
    }
};