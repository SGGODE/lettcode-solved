class Trie {
public:
    Trie() {
        
    }
    unordered_map<string,int>mp;
    void insert(string word) {
        mp[word]++;
    }
    
    bool search(string word) {
        return mp.count(word);
    }
    
    bool startsWith(string prefix) {
        for(auto it:mp){
            string x=it.first;
            int n=prefix.size();
           // for(int )
            string sub=x.substr(0,n);
            if(prefix==sub)return 1;
         //   if()
        }
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */