class Solution {
private:
    bool check(map<char,int>&mp,map<char,int>&mx,string s,string x){
        map<char,int>xc,dc;
        for(auto&it:s)xc[it]++;
        for(auto&it:x)dc[it]++;
        for(auto&it:xc){
            if(dc.count(it.first)){
                if(it.second!=dc[it.first])return 0;
            }
            else return 0;
        }
        if(mp.size()!=mx.size())return 0;
        for(auto&it:mp){
            if(mx.count(it.first)){
                if(it.second!=mx[it.first])return 0;
            }else return 0;
        }
        return 1;
    }
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        // int cnt=0;
        // map<string,map<char,int>>mp;
        // for(int i=0;i<words.size();i++){
        //     map<char,int>mx;
        //     int m = words[i].size();
        //     for(int j=0;j<m;j++){
        //       if(j%2==0)mx[words[i][j]]=0;
        //        else mx[words[i][j]]=1;
        //     }
        //     mp[words[i]]=mx;
        // }
        // vector<bool>vis(n,0);
        // for(int i=0;i<n;i++){
        //   if(!vis[i]){
        //       vis[i]=1;
        //       ++cnt;//cout<<words[i]<<" ";
        //     for(int j=i+1;j<n;j++){
        //         //for(auto&it:mp[words[j]])cout<<it.first<<" "<<it.second<<endl;
        //       //  for(auto&it:mp[words[i]])cout<<it.first<<" "<<it.second<<endl;
        //         if(check(mp[words[i]],mp[words[j]],words[i],words[j])){
        //             vis[j]=1;
        //            // cout<<words[j]<<" ";
        //         }
        //      }
        //      // cout<<endl;
        //   }
        // }
        // return cnt;
        unordered_set<string>s;
        for(int i=0;i<n;i++){
            string x1,x2;
            for(int j=0;j<words[i].size();j++){
                if(j%2)x1.push_back(words[i][j]);
                else x2.push_back(words[i][j]);
            }
            sort(x1.begin(),x1.end());
            sort(x2.begin(),x2.end());
            s.insert(x1+x2);
        }
        return s.size();
    }
};