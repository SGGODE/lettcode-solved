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
//     void left(TreeNode*&root,vector<int>&preorder,int j){
//         int j=1;
//         queue<TreeNode*>pq;
//         while(preorder[j]<root->val){
            
//         }
//     }
    // TreeNode* make_it(vector<int>&nums){
    //     if(nums.size() == 0) return NULL;
    //     if(nums.size() == 1)
    //     {
    //         return new TreeNode(nums[0]);
    //     }
    //     int mid=nums.size()/2;
    //     TreeNode* root=new TreeNode(nums[mid]);
    //     vector<int> levie(nums.begin(),nums.begin()+mid);
    //     vector<int> rigtvie(nums.begin()+mid+1,nums.end());
    //     root->left=make_it(levie);
    //     root->right=make_it(rigtvie);
    //     return root;
    // }
    void insert(TreeNode*&root,int val){
        if(root==NULL){
            root=new TreeNode(val);
            return;
        }
        if(root->val>val){
            insert(root->left,val);
        }
        if(root->val<val){
            insert(root->right,val);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& nums) {
       TreeNode* root=new TreeNode(nums[0]);
       TreeNode* temp=root;
        for(int i=1;i<nums.size();i++){
            insert(root,nums[i]);
        }
        return temp;
    }
};