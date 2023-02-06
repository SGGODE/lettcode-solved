class Solution {
private:
    // bool check(string s,string x,string p,unordered_map<char,int>&mp){
    //     int n=p.size();
    //     int m=s.size();
    //     for(int i=0;i<x.size();i++){
    //         if(mp.find(x[i])==mp.end()){
    //             return 0;
    //         }else{
    //             --mp[x[i]];
    //             if(mp[x[i]]==0)mp.erase(x[i]);
    //         }
    //     }
    //     //if(i!=(index+p.size()))return 0;
    //     return 1;
    // }
     // bool check(string s,string p){
     //     sort(s.begin(),s.end());
     //     for(int i=0;i<s.size();i++){
     //         if(s[i]!=p[i])return 0;
     //     }
     //     return 1;
     // }
public:
    // vector<int> findAnagrams(string s, string p) {
    //     // unordered_map<char,int>mp;
    //     // vector<int>v;
    //     // int m=p.size();
    //     // for(auto it:p)mp[it]++;
    //     // for(int i=0;i<s.size();i++){
    //     //     if(mp.find(s[i])!=mp.end()){
    //     //         string x=s.substr(i,i+m);
    //     //         cout<<x<<endl;
    //     //         unordered_map<char,int>cp(mp);
    //     //        if(check(s,x,p,cp))
    //     //           v.push_back(i);
    //     //     }
    //     // }
    //     // return v;
    //     vector<pair<string,int>>v;
    //     for(int i=0;i<s.size();i++){
    //         string x="";
    //         for(int j=i;j<i+p.size()&&j<s.size();j++){
    //             x+=s[j];
    //         }
    //         if(x.size()==p.size())
    //          v.push_back({x,i});
    //     }
    //     sort(p.begin(),p.end());
    //     vector<int>result;
    //     for(auto it:v){
    //         string dump=it.first;
    //         sort(dump.begin(),dump.end());
    //         if(dump==p){
    //             result.push_back(it.second);
    //         }
    //     }
    //     return result;
    // }
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }
};