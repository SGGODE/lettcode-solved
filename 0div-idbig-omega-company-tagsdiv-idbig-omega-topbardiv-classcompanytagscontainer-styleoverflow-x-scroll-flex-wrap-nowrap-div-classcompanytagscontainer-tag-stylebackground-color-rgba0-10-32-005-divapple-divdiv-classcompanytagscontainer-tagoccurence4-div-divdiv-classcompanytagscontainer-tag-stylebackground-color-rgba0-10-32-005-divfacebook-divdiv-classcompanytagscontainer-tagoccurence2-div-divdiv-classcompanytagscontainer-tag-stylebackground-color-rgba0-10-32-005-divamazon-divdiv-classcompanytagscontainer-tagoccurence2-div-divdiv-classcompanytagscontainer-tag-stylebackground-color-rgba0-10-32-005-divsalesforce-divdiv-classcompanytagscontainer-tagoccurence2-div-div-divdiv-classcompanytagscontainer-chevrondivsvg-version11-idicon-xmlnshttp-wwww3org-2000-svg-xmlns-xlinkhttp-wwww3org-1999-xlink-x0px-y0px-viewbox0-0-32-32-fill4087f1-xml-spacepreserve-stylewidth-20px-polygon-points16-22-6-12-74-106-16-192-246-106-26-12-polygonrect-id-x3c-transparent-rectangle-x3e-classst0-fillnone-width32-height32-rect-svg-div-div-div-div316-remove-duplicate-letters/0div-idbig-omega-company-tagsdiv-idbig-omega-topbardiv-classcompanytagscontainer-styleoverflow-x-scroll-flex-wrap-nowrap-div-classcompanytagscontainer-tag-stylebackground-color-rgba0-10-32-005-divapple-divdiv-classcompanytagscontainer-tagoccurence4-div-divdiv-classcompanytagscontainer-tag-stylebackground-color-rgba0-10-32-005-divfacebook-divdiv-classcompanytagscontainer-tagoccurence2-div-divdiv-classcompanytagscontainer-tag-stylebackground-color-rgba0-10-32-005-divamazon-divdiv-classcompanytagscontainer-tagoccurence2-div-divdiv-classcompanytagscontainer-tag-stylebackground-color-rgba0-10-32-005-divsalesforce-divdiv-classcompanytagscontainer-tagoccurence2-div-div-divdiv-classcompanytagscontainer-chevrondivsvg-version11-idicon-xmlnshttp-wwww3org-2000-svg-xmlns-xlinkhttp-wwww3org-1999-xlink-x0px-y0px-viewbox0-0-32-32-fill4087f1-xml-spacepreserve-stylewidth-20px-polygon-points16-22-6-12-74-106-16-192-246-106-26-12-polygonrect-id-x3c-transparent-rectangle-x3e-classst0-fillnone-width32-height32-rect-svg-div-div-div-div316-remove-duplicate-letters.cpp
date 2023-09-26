class Solution {
private:
    string sub(string&s,string&x,int index,set<char>&ch,int n){
        if(ch.size()==n){
            return x;
        }
        if(index==s.size()){
            return s;
        }
        string notpick = sub(s,x,index+1,ch,n);
        string pick = s;
        if(!ch.count(s[index])){
           ch.insert(s[index]);
           x.push_back(s[index]);
           pick = min(pick,sub(s,x,index+1,ch,n));
           ch.erase(s[index]);
           x.pop_back();
        }
        return min(notpick,pick);
    }
   map<pair<int,int>,string>dp;
   string&mi(string&x,string&s){
       if(x.size()<s.size())return x;
       return x<s?x:s;
   }
   string subs(string&s,string&temp,map<char,vector<int>>&mp,set<int>&st,int index){
       if(index==temp.size()){
           string res;
           for(auto&it:st)res.push_back(s[it]);
           return res.size()==temp.size()?res:s;
       }
       string ans = s;
       for(auto&it:mp[temp[index]]){
           st.insert(it);
           string x=subs(s,temp,mp,st,index+1);
           ans = mi(x,ans);
           st.erase(it);
       }
       return ans;
   }
public:
    string removeDuplicateLetters(string s) {
        // set<char>st;
        // for(auto&it:s)st.insert(it);
        // int n = st.size();
        // string x;
        // set<char>ch;
        // return sub(s,x,0,ch,n);
        // map<char,vector<int>>mp;
        // string temp;
        // for(int i=0;i<s.size();i++){
        //     if(!mp.count(s[i]))temp.push_back(s[i]);
        //     mp[s[i]].push_back(i);
        // }
        // // for(auto&it:mp){
        // //     cout<<it.first<<" ";
        // //     for(auto vt:it.second)cout<<vt<<" ";
        // //     cout<<endl;
        // // }
        // set<int>st;
        // return subs(s,temp,mp,st,0);
        stack<char>ch;
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[int(s[i])-97]=i;
        }
        vector<bool>vis(26,0);
        string x;
        for(int i=0;i<s.size();i++){
             if(vis[s[i]-'a'])continue;
              while(!ch.empty()&&last[int(ch.top())-97]>i&&s[i]<ch.top()){
                    vis[int(ch.top())-97]=0;
                    ch.pop();
               }
            ch.push(s[i]);
            vis[s[i]-'a']=1;
        }
        while(!ch.empty()){
            x.push_back(ch.top());
            ch.pop();
        }
        reverse(x.begin(),x.end());
        return x;
    }
};