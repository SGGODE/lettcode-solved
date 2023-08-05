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
    void sub(vector<vector<int>>&res,vector<int>&temp,int index){
        if(index==temp.size())res.push_back(temp);
        for(int i=index;i<temp.size();i++){
            swap(temp[i],temp[index]);
            sub(res,temp,index+1);
            swap(temp[i],temp[index]);
        }
    }
    void seq(TreeNode* root,vector<int>&res){
        for(int i=0;i<res.size();i++){
            if(res[i]!=-1){
                add(root,res[i]);
            }
        }
    }
    void add(TreeNode* root,int value){
        if(root==NULL)return;
        if(root->val>value){
            if(root->left==NULL){
                root->left=new TreeNode(value);
            }else{
                add(root->left,value);
            }
        }else{
            if(root->right==NULL){
                root->right=new TreeNode(value);
            }else{
                add(root->right,value);
            }
        }
    }
    void inorder(TreeNode* root,vector<int>&prev){
        if(root==NULL){
             prev.push_back(-1);
            return;
        }
         prev.push_back(root->val);
        inorder(root->left,prev);
        inorder(root->right,prev);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>res;
        vector<int>temp;
        for(int i=1;i<=n;i++)temp.push_back(i);
        vector<vector<int>>result;
        sub(result,temp,0);
        map<vector<int>,int>mp;
        for(int i=0;i<result.size();i++){
            //if(!mp.count(store[i])){
            TreeNode* root = new TreeNode(result[i][0]);
            result[i][0]=-1;
            seq(root,result[i]);
            vector<int>prev;
            inorder(root,prev);
            if(!mp.count(prev)){
                res.push_back(root);
                mp[prev]++;
            }
          //  mp[root]++;
          //  }
        }
        return res;
    }
};