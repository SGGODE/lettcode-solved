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
    void maketreeleft(TreeNode* root,vector<int>&v){
        queue<TreeNode*>pq;
       // pq.push(root);
        root->left=new TreeNode(v[0]);
        int n=v.size();
        int j=1;
        root=root->left;
         pq.push(root);
        TreeNode* temp=new TreeNode(10000000);
        pq.push(temp);
        while(!pq.empty()){
            TreeNode* curr=pq.front();
            pq.pop();
            bool flag=0;
            if(pq.front()==temp){
                pq.pop();
                flag=1;
            }
            if(j<n){
               curr->left=new TreeNode(v[j]);
               pq.push(curr->left);
                ++j;
            }if(j<n){
               curr->right=new TreeNode(v[j]);
               pq.push(curr->right); 
                ++j;
            }
        }
    }
    void balance(TreeNode* root){
        if(root==NULL)return;
        if(root->left->val > root->val){
            int x=root->val;
            root->val=root->left->val;
            root->left->val=x;
            balance(root->left);
           // return;
        }
        if(root->right->val < root->val){
            int x=root->val;
            root->val=root->right->val;
            root->right->val=x;
            balance(root->right);
            //return;
        }
       // return;
    }
   void maketreeright(TreeNode* root,vector<int>&v){
        queue<TreeNode*>pq;
       // pq.push(root);
        root->right=new TreeNode(v[0]);
        //cout<<v[0]<<endl;
        int n=v.size();
        int j=1;
        root=root->right;
         pq.push(root);
        TreeNode* temp=new TreeNode(10000000);
        pq.push(temp);
        while(!pq.empty()){
            TreeNode* curr=pq.front();
            pq.pop();
            bool flag=0;
            if(pq.front()==temp){
                pq.pop();
                flag=1;
            }
            if(j<n){
               curr->left=new TreeNode(v[j]);
               pq.push(curr->left);
                ++j;
            }if(j<n){
               curr->right=new TreeNode(v[j]);
               pq.push(curr->right); 
                ++j;
            }
        }
    }
    TreeNode* list(vector<int>&nums){
        if(nums.size()==0)return NULL;
        if(nums.size()==1)return new TreeNode(nums[0]);
        int mid=nums.size()/2;
        TreeNode* root=new TreeNode(nums[mid]);
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid+1,nums.end());
        root->left=list(left);
        root->right=list(right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        int n=v.size();
        if(n==1){
            TreeNode* temp=new TreeNode(v[0]);
            return temp;
        }
        if(n==2){
            TreeNode* temp=new TreeNode(v[0]);
            if(v[1]>v[0]){
                temp->right=new TreeNode(v[1]);
                return temp;
            }else{
                 temp->left=new TreeNode(v[1]);
                return temp;
            }
        }
      return list(v);
    }
};