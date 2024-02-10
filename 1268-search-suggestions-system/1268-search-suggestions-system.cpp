class Node{
public:
    Node *links[26];
    bool flag=0;
    bool contain(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=1;
    }
    bool isend(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contain(word[i])){
                node->put(word[i],new Node());
            }
            node =node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contain(word[i])){
                return 0;
            }
            node =node->get(word[i]);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->contain(prefix[i])){
                return 0;
            }
            node =node->get(prefix[i]);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //Trie t = new Trie();
        // for(auto&it:products){
        //     t.insert(it);
        // }
        map<string,vector<string>>mp;
        for(auto&it:products){
            string res;
            for(auto&vt:it){
                res.push_back(vt);
                mp[res].push_back(it);
            }
        }
        string temp;
        vector<vector<string>>result;
        for(auto&it:searchWord){
            temp.push_back(it);
            vector<string>curr=mp[temp];
            sort(curr.begin(),curr.end());
            if(!curr.empty()&&curr.size()>=3)result.push_back({curr[0],curr[1],curr[2]});
            else if(!curr.empty()&&curr.size()==2)result.push_back({curr[0],curr[1]});
            else if(!curr.empty()&&curr.size()==1)result.push_back({curr[0]});
            else result.push_back({});
        }
        return result;
    }
};