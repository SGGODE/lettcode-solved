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
    string ans;
    void sub(TreeNode* root,map<int,char>&mp,string pat){
        if(root->left==NULL&&root->right==NULL){
            pat.push_back(mp[root->val]);
            reverse(pat.begin(),pat.end());
            if(ans.empty())ans=pat;
            else ans = min(ans,pat);
            return;
        }
        pat.push_back(mp[root->val]);
        if(root->left)sub(root->left,mp,pat);
        if(root->right)sub(root->right,mp,pat);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        char ch ='a';
        map<int,char>mp;
        for(int i=0;i<26;i++){
            mp[i]=ch+i;
        }
        sub(root,mp,"");
        return ans;
    }
};