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
    vector<int>tree;
    void preorder(TreeNode* root){
         if(root==NULL)return;
        preorder(root->left);
        tree.push_back(root->val);
        preorder(root->right);
    }
    int getmin(int x){
        // vector<int>::iterator it;
        // it=find(tree.begin(),tree.end(),x);
        // if(it!=tree.end())
        //   return x;
        int ans=-1;
        // vector<int>::iterator lower;
        // lower = lower_bound(tree.begin(),tree.end(), x);
        // if(lower!=tree.end())
        // return tree[lower - tree.begin() + 1];
         int s=0;
         int e=tree.size()-1;
       while(s<=e){
            int mid=s+(e-s)/2;
            if(tree[mid]<=x){
              if(tree[mid]==x)
                return x;
              ans=tree[mid];
              s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
    int getmax(int y){
        // vector<int>::iterator it;
        // it=find(tree.begin(),tree.end(),y);
        // if(it!=tree.end())
        //   return y;
        int ans=-1;
        // vector<int>::iterator upper;
        // upper = upper_bound(tree.begin(),tree.end(), y);
        // if(upper!=tree.end())
        // return tree[upper - tree.begin() + 1];
        int s=0;
        int e=tree.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(tree[mid]>=y){
              if(tree[mid]==y)
                return y;
              ans=tree[mid];
              e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        preorder(root);
        vector<vector<int>>v;
        for(int i=0;i<queries.size();i++){
            int x=getmin(queries[i]);
            int y=getmax(queries[i]);
            v.push_back({x,y});
        }
        return v;
    }
};