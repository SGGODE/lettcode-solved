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
    int deepestLeavesSum(TreeNode* root) {
        vector<int>store;
        vector<int>last;
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode* temp = new TreeNode(101);
        pq.push(temp);
        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();
            store.push_back(node->val);
            if(node->left){
                pq.push(node->left);
            }
            if(node->right){
                pq.push(node->right);
            }
            if(pq.front()==temp){
                pq.pop();
                pq.push(temp);
                last.clear();last=store;
                store.clear();
            }
        }
        int sum=0;
        for(auto&it:last)sum+=it;
        return sum;
    }
};