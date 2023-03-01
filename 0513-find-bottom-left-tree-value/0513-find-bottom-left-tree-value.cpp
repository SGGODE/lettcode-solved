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
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return root->val;
        vector<pair<int,pair<char,int>>>v; 
        queue<TreeNode*>pq;
        TreeNode* z=new TreeNode(INT_MAX);
        pq.push(z);
        pq.push(root);
        pq.push(z);
        int cnt=0;
        while(!pq.empty()){
            TreeNode* temp=pq.front();
            pq.pop();bool flag=0;
            if(pq.front()==z){
                flag=1;
                pq.pop();
            }
            if(temp->left){
                v.push_back({cnt+1,{'L',temp->left->val}});
                pq.push(temp->left);
            }
            if(temp->right){
                v.push_back({cnt+1,{'R',temp->right->val}});
                pq.push(temp->right);
            }
            if(flag){
                 ++cnt;
                 pq.push(z);
            }
           
        }
        int maxval=INT_MIN;
        int max_node=2147483648;
        for(auto it:v){
            if(it.first>maxval){
                maxval=it.first;
                max_node=it.second.second;
            }
        }
        if(max_node==2147483648)return root->val;
        return max_node;
    }
};