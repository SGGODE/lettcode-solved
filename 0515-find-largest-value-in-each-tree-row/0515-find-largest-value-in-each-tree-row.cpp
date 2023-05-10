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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>res;
        vector<int>temp;
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode* vx= new TreeNode(4294967296);
        pq.push(vx);
        while(!pq.empty()){
            TreeNode* curr=pq.front();
            pq.pop();
            bool flag=0;
            if(pq.front()==vx){
                flag=1;
                pq.pop();
            }
            temp.push_back(curr->val);
            if(curr->left){
                pq.push(curr->left);
            }
            if(curr->right){
                pq.push(curr->right);
            }
            if(flag){
                int m=*max_element(temp.begin(),temp.end());
                res.push_back(m);
                temp.clear();
                pq.push(vx);
            }
        }
        return res;
    }
};