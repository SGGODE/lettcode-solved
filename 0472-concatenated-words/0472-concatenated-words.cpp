class Solution {
private:
    bool dfs(string s,unordered_map<string,int>&mp){
        int n=s.size();
        for(int i=1;i<n;i++){
            string f=s.substr(0,i);
            string se=s.substr(i,n);
            if((mp.find(f)!=mp.end()&&mp.find(se)!=mp.end())||(mp.find(f)!=mp.end()&&dfs(se,mp))){
                return 1;
            }
        }
        return 0;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>mp;
        int n=words.size();
        for(auto it:words)mp[it]++;
        vector<string>v;
        // for(int i=0;i<n;i++){
        //     --mp[words[i]];
        //     string s=words[i];
        //     string x;int cnt=0;
        //     for(int j=0;j<s.size();j++){
        //          x.push_back(s[j]);
        //          if(mp.find(x)!=mp.end()){
        //              ++cnt;
        //              x.clear();
        //          }
        //     }
        //     if(cnt>=2)v.push_back(words[i]);
        //      mp[words[i]]++;
        // }
        for(int i=0;i<n;i++){
            if(dfs(words[i],mp)){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};