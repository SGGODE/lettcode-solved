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
        while(!pq.empty()) {
            root=pq.front(); //get the value 
            pq.pop();
            if (root->right) {
                pq.push(root->right);
            }
            if(root->left)pq.push(root->left);
        }
        return root->val;
    }
};