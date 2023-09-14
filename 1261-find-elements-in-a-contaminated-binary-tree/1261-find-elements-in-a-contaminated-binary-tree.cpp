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
class FindElements {
public:
    TreeNode* tree;
    FindElements(TreeNode* root) {
       tree=root;
       makeit(tree,0);
    }
    void makeit(TreeNode* root,int value){
        if(root==NULL)return;
        root->val=value;
        makeit(root->left,(2*value)+1);
        makeit(root->right,(2*value)+2);
    }
    bool findthenode(TreeNode* temp,int node){
        if(temp==NULL)return 0;
        if(temp->val==node)return 1;
        return (findthenode(temp->right,node)||findthenode(temp->left,node)); 
    }
    bool find(int target) {
        return findthenode(tree,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */