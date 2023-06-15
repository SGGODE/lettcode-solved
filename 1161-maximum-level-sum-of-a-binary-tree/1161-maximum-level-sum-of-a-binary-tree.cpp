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
    int maxLevelSum(TreeNode* root) {
        priority_queue<pair<int,int>>pq;
        int sum=0;
        int level=0;
        queue<TreeNode*>carry;
        carry.push(root);
        TreeNode* temp=new TreeNode(1e9);
        carry.push(temp);
        int maxsum=INT_MIN;
        int reslevel=1;
        while(!carry.empty()){
            TreeNode* Node=carry.front();
            carry.pop();
            sum+=Node->val;
            bool alert=0;
            if(carry.front()==temp){
                carry.pop();
                alert=1;
            }
            if(Node->left){
                carry.push(Node->left);
            }
            if(Node->right){
                carry.push(Node->right);
            }
            if(alert){
                ++level;
                pq.push({sum,level});
                if(sum>maxsum){
                    maxsum=sum;
                    reslevel=level;
                }
                sum=0;
                carry.push(temp);
            }
        }
        return reslevel;
    }
};