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
class Solution {
private:
   ll mod=1e9+7;
    ll tot=0;
    int SumTree(TreeNode*root) {
        if(root==NULL)return 0;
        return SumTree(root->left)+SumTree(root->right)+root->val;
    }
     int theTree(TreeNode* root) {
        if(root == NULL)    return 0;
        if(root->left == NULL and root->right == NULL)
            return root->val;
        int leftSum =theTree(root->left);
        int rightSum = theTree(root->right);
        
        root->val += leftSum+rightSum;
        return root->val;
    }
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    void maxsum(TreeNode* root,long long& maxpr){
        if(root==NULL)return;
        // if(root->left){
        //     int left=root->left->val;
        //     int res=holesum-left;
        //     if((res*left)>maxpr){
        //         maxpr=res*left;
        //     }
        // }
        // if(root->right){
        //     int right=root->right->val;
        //     int res=holesum-right;
        //     if((res*right)>maxpr){
        //         maxpr=res*right;
        //     }
        // }
        if(root->left) {
            long long sum1 = root->left->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > maxpr)
                maxpr = curr;
        }
        
        // maximise sum from right
        if(root->right) {
            long long sum1 = root->right->val;
            long long sum2 = tot - sum1;
            long long curr = sum1*sum2;
            if(curr > maxpr)
                maxpr = curr;
        }
        if(root->left)maxsum(root->left,maxpr);
        if(root->right)maxsum(root->right,maxpr);
    }
    // void maxprod(TreeNode* root){
    //     if(root==NULL)return;
    //     //long long int currsum=SumTree(root);
    //   //  long long int upsum=;//-currsum;
    //     ll leftsum=SumTree(root->left);
    //     ll rightsum=SumTree(root->right);
    //     ll upsum=holesum-((ll)leftsum+rightsum+root->val);
    //     ll x=upsum*((ll)leftsum+rightsum+root->val);
    //     ll y=leftsum*((ll)upsum+rightsum+root->val);
    //     ll z=rightsum*((ll)upsum+leftsum+root->val);
    //     maxpr=max(maxpr,max(x,max(y,z)));
    //   //  if(root->left)maxprod(root->left);
    //    // if(root->right)maxprod(root->right);
    //    // return leftsum+rightsum+root->val;
    // }
public:
    int maxProduct(TreeNode* root) {
        tot=SumTree(root);
      // if(root==NULL)return;
       // maxprod(root);
      //// return maxpr%(int)(1e9 + 7);
       theTree(root);
        ll maxpr=0;
       maxsum(root,maxpr);
        //inorder(root);
        //cout<<endl;
       // return 110;
      return maxpr%(int)(1e9 + 7);
    }
};