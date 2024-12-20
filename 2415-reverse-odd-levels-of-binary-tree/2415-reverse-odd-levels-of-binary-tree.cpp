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
    TreeNode* solve(TreeNode* root){
       // vector<pair<int,vector<int>>>levels;
        // 2 * i + 1  
        vector<int>result;
        queue<TreeNode*>pq;
        pq.push(root);
        int level = 0;
        while(!pq.empty()){
            vector<int>temp;
            int size = pq.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = pq.front();
                pq.pop();
                temp.push_back(node->val);
                if(node->left)pq.push(node->left);
                if(node->right)pq.push(node->right);
            }
            if(level%2)reverse(temp.begin() , temp.end());
            for(auto&it:temp)result.push_back(it);
            ++level;
        }
        int sizeOfResult = result.size();
        TreeNode* newRoot = new TreeNode(result[0]);
        TreeNode* pointNewRoot = newRoot;
        queue<pair<TreeNode*,int>>pqx;
        pqx.push({newRoot , 0});
        while(!pqx.empty()){
            TreeNode* node = pqx.front().first;
            int index = pqx.front().second;
            pqx.pop();
            if((2*index) + 1 < sizeOfResult){
                node->left = new TreeNode(result[(2*index)+1]);
                pqx.push({node->left , (2*index)+1});
            }
            if((2*index) + 2 < sizeOfResult){
                node->right = new TreeNode(result[(2*index)+2]);
                pqx.push({node->right , (2*index)+2});
            }
        }
        return pointNewRoot;
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        return solve(root);
    }
};