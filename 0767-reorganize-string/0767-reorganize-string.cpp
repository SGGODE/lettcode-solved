class Solution {
private:
    string res;
    bool check(string x){
        int n=x.size();
        for(int i=1;i<n;i++){
            if(x[i]==x[i-1]){
                return 0;
            }
        }
        res=x;
        cout<<res<<endl;
        return 1;
    }
    bool result(vector<bool>&vis,string&s,string&res,int index){
        if(index==s.size()){
            if(res.size()!=s.size()){
                return result(vis,s,res,0);
            }else{
                return check(res);
            }
        }
        bool notpick=result(vis,s,res,index+1);
        if(notpick)return 1;
        bool pick=0;
        if(!vis[index]){
            res.push_back(s[index]);
            vis[index]=1;
            pick=result(vis,s,res,index+1);
            if(pick)return 1;
            res.pop_back();
            vis[index]=0;
        }
        return (pick||notpick);
    }
public:
    string reorganizeString(string s) {
       map<char,int>mp;
        for(auto&it:s)mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto&it:mp){
            pq.push({it.second,it.first});
        }
        int n=s.size();
        if(pq.top().first>(n+1)/2)return "";
        string res;
        while(pq.size()>1){
           auto it=pq.top();
           pq.pop();
           auto it1=pq.top();
            pq.pop();
            res.push_back(it.second);
            res.push_back(it1.second);
            if(it.first>1)pq.push({it.first-1,it.second});
             if(it1.first>1)pq.push({it1.first-1,it1.second});
           // if(freq!=0)return "";
        }
        if(pq.size())res.push_back(pq.top().second);
        return res;
    }
};