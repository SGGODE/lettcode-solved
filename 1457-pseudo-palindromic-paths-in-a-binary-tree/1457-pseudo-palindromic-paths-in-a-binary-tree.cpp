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
    bool check(int count[]){
	int odd = 0;
	for (int i = 0; i < 10; i++) {
		if (count[i] & 1)
			odd++;

		if (odd > 1)
			return false;
	}
	return true;
 }
   int sub(TreeNode* root,int arr[]){
       int ans = 0;
       arr[root->val]++;
       if(root->left==NULL&&root->right==NULL){
           if(check(arr)){
               arr[root->val]--;
               return 1;
           }
           else{
              arr[root->val]--;
             return 0;  
           } 
       }
       if(root->right!=NULL)ans += sub(root->right,arr);
       if(root->left!=NULL)ans += sub(root->left,arr);
       arr[root->val]--;
       return ans;
   }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        string s;
        int arr[10];
        return sub(root,arr);
    }
};