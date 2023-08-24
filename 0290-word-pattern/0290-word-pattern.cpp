class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string sx,x;
        int cnt=0;
        map<char,int>mp;
        map<string,int>mx;
        for(auto&it:pattern){
            if(mp.count(it)){
                sx.push_back(mp[it]);
            }else{
                cnt+=1;
                mp[it]=cnt;
                sx.push_back(mp[it]);
            }
        }
        string word;
        stringstream ss(s);
        cnt=0;
        while(ss>>word){
            //cout<<word<<endl;
            if(mx.count(word)){
                x.push_back(mx[word]);
            }else{
                cnt+=1;
                mx[word]=cnt;
                x.push_back(mx[word]);
            }
        }
        
        return sx==x;
    }
};