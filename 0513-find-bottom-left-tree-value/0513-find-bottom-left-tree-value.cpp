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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode *temp = new TreeNode(1000);
        pq.push(temp);
        vector<int>value;
        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();
            value.push_back(node->val);
            if(node->left){
                 pq.push(node->left);
            }
            if(node->right){
                pq.push(node->right);
            }
            if(pq.front()==temp){
                pq.pop();
                if(!pq.empty()){
                    value.clear();
                    pq.push(temp);
                }
            }
        }
        return value[0];
    }
};