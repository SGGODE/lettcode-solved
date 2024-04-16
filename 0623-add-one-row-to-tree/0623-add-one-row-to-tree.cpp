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
    void sub(TreeNode* root,int value,int depth){
        queue<pair<TreeNode*,int>>pq;
        TreeNode* temp = new TreeNode(-1);
        pq.push({root,2});
        while(!pq.empty()){
            TreeNode* node = pq.front().first;
            int d = pq.front().second;
            //cout<<node->val<<" "<<d<<endl;
            pq.pop();
            if(d==depth){
                if(node->left){
                    TreeNode* nodeleft = node->left;
                    node->left = new TreeNode(value);
                    node->left->left = nodeleft;
                }else{
                    node->left =new TreeNode(value);
                }
                if(node->right){
                    TreeNode* noderight = node->right;
                    node->right = new TreeNode(value);
                    node->right->right = noderight;
                    
                }else{
                    node->right =new TreeNode(value);
                }
                //break;
            }else{
                if(node->left){
                    pq.push({node->left,d+1});
                }
                if(node->right){
                    pq.push({node->right,d+1});
                }
            }
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* rroot = new TreeNode(val);
            rroot->left=root;
            return rroot;
        }
        TreeNode* rroot = root;
        sub(root,val,depth);
        return root;
    }
};