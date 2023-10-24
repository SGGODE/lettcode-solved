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
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode* temp = new TreeNode(INT_MAX);
        pq.push(temp);
        int val = INT_MIN;
        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();bool flag = 0;
            if(pq.front()==temp)flag=1;
            val = max(val,node->val);
            if(node->left){
                pq.push(node->left);
            }
            if(node->right){
                pq.push(node->right);
            }
            if(flag){
                pq.pop();
                pq.push(temp);
                res.push_back(val);
                val=INT_MIN;
            }
        }
        return res;
    }
};