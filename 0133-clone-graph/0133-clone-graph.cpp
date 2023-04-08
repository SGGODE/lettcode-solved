/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* node,unordered_map<Node*,Node*>&mp){
        vector<Node*>neighbors;
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto it:node->neighbors){
            if(mp.count(it)){
                neighbors.push_back(it);
            }else{
                neighbors.push_back(dfs(it,mp));
            }
        }
        node->neighbors=neighbors;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
    //    if(node==NULL)return NULL;
    //    if(node->neighbors.size()==0){
    //        Node* clone=new Node(node->val);
    //        return clone;
    //    }
    //    unordered_map<Node*,Node*>mp;
    //    return dfs(node,mp);
    // }
         if(node==nullptr) return node;
        unordered_map<Node*, Node*> ma;
        queue<Node*> q;
        Node *t = new Node(node->val);
        Node *head = t;
        q.push(node);
        ma[node] = t;
        
        while(q.size()){
            for(auto a: q.front()->neighbors)
                if(ma.count(a)==0){
                    t = new Node(a->val);
                    ma[a] = t;
                    q.push(a);
                }
            q.pop();
        }
        
        for(auto a: ma){
            t = a.second;
            for(auto b:a.first->neighbors)
                a.second->neighbors.push_back(ma[b]);
        }
        
        return head;
    }
};