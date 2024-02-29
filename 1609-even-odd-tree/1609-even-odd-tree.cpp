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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>pq;
        pq.push(root);
        int level = 0;
        while(!pq.empty()){
            int size = pq.size();
            int prev = level%2==0?-1:1e9;
            for(int i=0;i<size;i++){
                TreeNode* node = pq.front();
                pq.pop();
                int curr = node->val;
                if(node->left)pq.push(node->left);
                if(node->right)pq.push(node->right);
                if(level%2==0&&!(curr%2!=0&&prev<curr))return 0;
                if(level%2!=0&&!(curr%2==0&&prev>curr))return 0;
                prev = curr;
            }
            ++level;
        }
        return 1;
    }
};