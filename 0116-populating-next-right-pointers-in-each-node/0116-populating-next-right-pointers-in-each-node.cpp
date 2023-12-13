/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        queue<Node*>pq;
        pq.push(root);
        Node* temp = new Node(1001);
        pq.push(temp);
        vector<Node*>res;
        while(!pq.empty()){
            Node* c = pq.front();
            pq.pop();bool f = 0;
            if(pq.front()==temp)f=1;
            res.push_back(c);
            if(c->left!=NULL){
                pq.push(c->left);
            }
            if(c->right!=NULL){
                pq.push(c->right);
            }
            if(f){
                pq.pop();
                int n = res.size();
                for(int i=1;i<res.size();i++){
                    res[i-1]->next=res[i];
                }
                res[n-1]->next=NULL;
                res.clear();
                pq.push(temp);
            }
        }
        return root;
    }
};