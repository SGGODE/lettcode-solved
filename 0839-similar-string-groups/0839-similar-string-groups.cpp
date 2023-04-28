class Solution {
private:
    bool difference(string s,string x){
        int cnt=0;
        for(int i=0;i<x.size();i++){
            if(s[i]!=x[i])++cnt;
        }
        return cnt<=2;
    }
    void dfs(vector<string>&strs,vector<bool>&vis,int index){
        vis[index]=1;
        for(int i=0;i<strs.size();i++){
            if(!vis[i]&&difference(strs[index],strs[i])){
                dfs(strs,vis,i);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        // unordered_map<int,string>mp;
        // unordered_map<string,int>mx;
        // set<int>st;
        // for(int i=0;i<n;i++){
        //     if(mx.count(strs[i]))st.insert(i);
        //     else{mp[i]=strs[i];mx[strs[i]]++;}
        // }
        // vector<int>adj[n+1];
        // for(int i=0;i<n;i++){
        //    if(st.find(i)!=st.end())continue;
        //     for(int j=0;j<n;j++){
        //         if(i==j)continue;
        //         else{adj[i].push_back(j);adj[j].push_back(i);}
        //     }
        // }
        vector<bool>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ++cnt;
                dfs(strs,vis,i);
            }
        }
        return cnt;
    }
};