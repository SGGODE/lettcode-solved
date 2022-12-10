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
#define ll long long
// class Solution {
// private:
//    ll mod=1e9+7;
//     ll holesum=0;
//     int SumTree(TreeNode*root) {
//         if(root==NULL)return 0;
//         return SumTree(root->left)+SumTree(root->right)+root->val;
//     }
//     void theTree(TreeNode* root){
//       if(root==NULL)return;
//       int left=SumTree(root->left);
//       int right=SumTree(root->right);
//       root->val=root->val+left+right;
//       if(root->left)theTree(root->left);
//       if(root->right)theTree(root->right);
//     }
//     void inorder(TreeNode* root){
//         if(root==NULL)return;
//         inorder(root->left);
//         cout<<root->val<<" ";
//         inorder(root->right);
//     }
//     void maxsum(TreeNode* root,long long& maxpr){
//         if(root==NULL)return;
//         // if(root->left){
//         //     int left=root->left->val;
//         //     int res=holesum-left;
//         //     if((res*left)>maxpr){
//         //         maxpr=res*left;
//         //     }
//         // }
//         // if(root->right){
//         //     int right=root->right->val;
//         //     int res=holesum-right;
//         //     if((res*right)>maxpr){
//         //         maxpr=res*right;
//         //     }
//         // }
//         if(root->left) {
//             long long sum1 = root->left->val;
//             long long sum2 = tot - sum1;
//             long long curr = sum1*sum2;
//             if(curr > res)
//                 res = curr;
//         }
        
//         // maximise sum from right
//         if(root->right) {
//             long long sum1 = root->right->val;
//             long long sum2 = tot - sum1;
//             long long curr = sum1*sum2;
//             if(curr > res)
//                 res = curr;
//         }
//         if(root->left)maxsum(root->left,maxpr);
//         if(root->right)maxsum(root->right,maxpr);
//     }
//     // void maxprod(TreeNode* root){
//     //     if(root==NULL)return;
//     //     //long long int currsum=SumTree(root);
//     //   //  long long int upsum=;//-currsum;
//     //     ll leftsum=SumTree(root->left);
//     //     ll rightsum=SumTree(root->right);
//     //     ll upsum=holesum-((ll)leftsum+rightsum+root->val);
//     //     ll x=upsum*((ll)leftsum+rightsum+root->val);
//     //     ll y=leftsum*((ll)upsum+rightsum+root->val);
//     //     ll z=rightsum*((ll)upsum+leftsum+root->val);
//     //     maxpr=max(maxpr,max(x,max(y,z)));
//     //   //  if(root->left)maxprod(root->left);
//     //    // if(root->right)maxprod(root->right);
//     //    // return leftsum+rightsum+root->val;
//     // }
// public:
//     int maxProduct(TreeNode* root) {
//         holesum=SumTree(root);
//       // if(root==NULL)return;
//        // maxprod(root);
//       //// return maxpr%(int)(1e9 + 7);
//        theTree(root);
//         ll maxpr=0;
//        maxsum(root,maxpr);
//         //inorder(root);
//         //cout<<endl;
//        // return 110;
//       return maxpr%(int)(1e9 + 7);
//     }
// };
class Solution {
    int tot = 0;
    int mod = 1e9+7;
public:
    // function to convert the tree into sum tree - this works in linear time
    int convert_To_SumTree(TreeNode* root) {
        if(root == NULL)    return 0;
        if(root->left == NULL and root->right == NULL)
            return root->val;
        int leftSum = convert_To_SumTree(root->left);
        int rightSum = convert_To_SumTree(root->right);
        
        root->val += leftSum+rightSum;
        return root->val;
    }
    void splitTree(TreeNode* root, long long& res) {
        if(root == NULL)
            return;
        
        // maximise sum from left
        if(root->left) {
            long long sum1 = root->left->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > res)
                res = curr;
        }
        
        // maximise sum from right
        if(root->right) {
            long long sum1 = root->right->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > res)
                res = curr;
        }
        
        // call  for left and right
        splitTree(root->left, res);
        splitTree(root->right, res);
    }
    int maxProduct(TreeNode* root) {
        // convert the tree into sum tree
        // so that each node stores the sum of its
        // left and right subtrees
        tot = convert_To_SumTree(root);
        
        if(tot == 0)    return 0;
        
        // now try to split at every location 
        // and get the maximum ans
        long long res = 0;
        splitTree(root, res);
        return res%mod;
    }
};