class Solution {
private:
   //   string&mi(string&x,string&s){
   //     if(x.size()<s.size())return x;
   //     return x<s?x:s;
   // }
   // string subs(string&s,string&temp,map<char,vector<int>>&mp,set<int>&st,int index){
   //     if(index==temp.size()){
   //         string res;
   //         for(auto&it:st)res.push_back(s[it]);
   //         return res.size()==temp.size()?res:s;
   //     }
   //     string ans = s;
   //     for(auto&it:mp[temp[index]]){
   //         st.insert(it);
   //         string x=subs(s,temp,mp,st,index+1);
   //         ans = mi(x,ans);
   //         st.erase(it);
   //     }
   //     return ans;
   // }
public:
    string smallestSubsequence(string s) {
       // map<char,vector<int>>mp;
       //  string temp;
       //  for(int i=0;i<s.size();i++){
       //      if(!mp.count(s[i]))temp.push_back(s[i]);
       //      mp[s[i]].push_back(i);
       //  }
       //  set<int>st;
       //  return subs(s,temp,mp,st,0);
        stack<char>st;
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<bool>vis(26,0);
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a'])continue;
            while(!st.empty()&&s[i]<st.top()&&last[st.top()-'a']>i){
                vis[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};