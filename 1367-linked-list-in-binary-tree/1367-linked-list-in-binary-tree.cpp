/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    map<pair<TreeNode*,ListNode*>,bool>dp;
    bool result(TreeNode* root , ListNode* curr , ListNode* head){
         if(curr == NULL)return true;
         if(root == NULL)return false;
         if(dp.count({root,curr}))return dp[{root,curr}];
         bool ans = false;
         if(root->val == curr->val){
             ans = result(root->left , curr->next , head) or 
                   result(root->right , curr->next , head) or 
                   result(root->left , head , head) or 
                   result(root->right , head , head);
         }else{
            ans = result(root->left , head , head) or result(root->right , head , head);
         }
        return dp[{root,curr}]=ans;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
       // memset(dp,-1,sizeof(dp));
        return result(root,head,head);
    }
};