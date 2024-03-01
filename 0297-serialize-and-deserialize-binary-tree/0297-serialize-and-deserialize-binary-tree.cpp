/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    void sub(TreeNode* root){
        queue<TreeNode*>pq;
        pq.push(root);
        TreeNode* temp = new TreeNode(1001);
        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();
            res.append(to_string(node->val));
            res.push_back(' ');
            if(node->val==1001)continue;
            if(node->left){
                pq.push(node->left);
            }else pq.push(temp);
            if(node->right){
                pq.push(node->right);
            }else pq.push(temp);
        }
        //return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(root==NULL)return to_string(1001);
      sub(root);
      return res;
    }
     TreeNode* buildTree(vector<int>& levelOrder){
        if (levelOrder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(levelOrder[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < levelOrder.size()) {
            TreeNode* node = q.front();
            q.pop();
            if(levelOrder[i] != 1001){
                node->left = new TreeNode(levelOrder[i]);
                q.push(node->left);
            }
            ++i;
            if(i < levelOrder.size() && levelOrder[i] != 1001){
                node->right = new TreeNode(levelOrder[i]);
                q.push(node->right);
            }
            ++i;
        }

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="1001")return NULL;
        stringstream ss(data);
        string word;
        vector<int>v;
        while(ss>>word){
            v.push_back(stoi(word));
        }
        return buildTree(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));