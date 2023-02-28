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
    void call(TreeNode* root,vector<TreeNode*>v){
        if(root==NULL)return;
        if(root->left==root->right){
            
        }
    }
    string inorder(TreeNode* root,vector<TreeNode*>&v,map<string,int>&mp){
        if(root==NULL){
           // v.push_back(NULL);
           // s.push_back('%,');
            return "%,";
        }
       string left = inorder(root->left,v,mp);
        string right=inorder(root->right,v,mp);
        string s= left +","+right+","+to_string(root->val);
        if(mp[s]==1){
           // flag=1;
            for(auto it:s){
                v.push_back(root);
            }
        }
        mp[s]++;
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>v;
        bool flag=0;
        map<string,int>mp;//string s;
        inorder(root,v,mp);
        set<TreeNode*>s(v.begin(),v.end());
       // v.clear();
        vector<TreeNode*>x(s.begin(),s.end());
    //     // for(auto it:v)cout<<it<<" ";
    //     // cout<<endl;
    //     string s;
    //     for(auto it:v){
    //         if(it==NULL)s.push_back('n');
    //        else s.push_back((it->val)+'0');
    //     }
    //     map<string,int>mp;
    //     for (int i = 0; i < s.length(); i++) {
    //     string subStr;
    //     // Second loop is generating sub-string
    //     for (int j = i; j < s.length(); j++) {
    //         subStr += s[j];
    //         mp[subStr]++;
    //     }
    // }
    //    // vector<vector<int>>x;
    //     vector<int>res; vector<TreeNode*>x;
    //     for(auto it:mp){
    //         if(it.second==2){
    //             for(auto vt:it.first)res.push_back(vt-'0');
    //              for(auto zt:res){
    //                TreeNode* temp=new TreeNode(zt);
    //                x.push_back(temp);
    //              }
    //             //break;
    //             res.clear();
    //         }
    //     }
    //     // x.push_back(res);
    //     //  x.push_back(res);
    //     // for(auto it:res){
    //     //     TreeNode* temp=new TreeNode(it);
    //     //     x.push_back(temp);
    //     // }
    //     //cout<<s<<endl;
    //     //return v;
        //sort(v.begin(),v.end());
        return x;
    }
};