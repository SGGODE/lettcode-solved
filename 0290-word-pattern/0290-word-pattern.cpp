class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,int>mp;
        int cnt=0;
        for(auto it:pattern){
            if(mp.find(it)==mp.end()){
                mp[it]=cnt+1;
                ++cnt;
            }
        }
        //for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        //return 1;
        stringstream ss(s);
        string word;
        cnt=0;
        map<string,int>mx;
        while (ss >> word){
            if(mx.find(word)==mx.end()){
                mx[word]=cnt+1;
                ++cnt;
            }
        }
        string pat,res;
        for(int i=0;i<pattern.size();i++){
            pat.append(to_string(mp[pattern[i]]));
           // cout<<mp[pattern[i]]<<endl;
        }
        stringstream sx(s);
        string wor;
         while(sx>>wor){
            res.append(to_string(mx[wor]));
            // cout<<mx[wor]<<endl;
        }
        return pat==res;
    }
};