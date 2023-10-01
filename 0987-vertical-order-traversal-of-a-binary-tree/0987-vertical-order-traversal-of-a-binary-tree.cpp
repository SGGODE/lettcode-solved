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
    void sub(map<int,vector<int>>&dp,TreeNode* root,int column){
        // if(root==NULL)return;
        // dp[column].push_back(root->val);
        // sub(dp,root->right,column+1);
        // sub(dp,root->left,column-1);
        queue<pair<TreeNode*,int>>pq;
        pq.push({root,0});
        TreeNode* temp = new TreeNode(1001);
        pq.push({temp,0});
        map<int,vector<int>>res;
        while(!pq.empty()){
            TreeNode* node = pq.front().first;
            int col = pq.front().second;
            pq.pop();bool flag = 0;
            if(pq.front().first==temp){
                flag=1;
            }
            res[col].push_back(node->val);
            if(node->left){
                pq.push({node->left,col-1});
            }
            if(node->right){
                pq.push({node->right,col+1});
            }
            if(flag){
                for(auto&it:res){
                    vector<int>j;
                    for(auto vt:it.second)j.push_back(vt);
                    sort(j.begin(),j.end());
                    for(auto&ht:j)dp[it.first].push_back(ht);
                }
                res.clear();
                pq.pop();
                pq.push({temp,0});
            }
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        sub(mp,root,0);
        vector<vector<int>>res;
        for(auto&it:mp){
            vector<int>temp;
            for(auto vt:it.second)temp.push_back(vt);
           if(!temp.empty()){
               //sort(temp.begin(),temp.end());
               res.push_back(temp);
           }
        }
        return res;
    }
};