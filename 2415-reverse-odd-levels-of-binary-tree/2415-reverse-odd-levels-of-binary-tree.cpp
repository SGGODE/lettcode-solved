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
    void sub(TreeNode* root,vector<int>&store,int index){
        if(((2*index)+1)>=store.size()&&((2*index)+2)>=store.size())return;
        if(((2*index)+1)<store.size()){
            root->left = new TreeNode(store[(2*index)+1]);
            sub(root->left,store,(2*index)+1);
        }
        if(((2*index)+2)<store.size()){
            root->right = new TreeNode(store[(2*index)+2]);
            sub(root->right,store,(2*index)+2);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
       // if(root==NULL)return root;
        //sub(root,0);
       // return root;
        vector<vector<int>>res;
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode* temp = new TreeNode(-1);
        pq.push(temp);
        vector<int>store;
        int cnt = 0;
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
                res.push_back(store);
                store.clear();
                pq.push(temp);
            }
        }
        for(int i=0;i<res.size();i++){
            if(i%2){
                reverse(res[i].begin(),res[i].end());
            }
        }
        store.clear();
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                store.push_back(res[i][j]);
            }
        }
        TreeNode* love = new TreeNode(store[0]);
        sub(love,store,0);
        return love;
    }
};