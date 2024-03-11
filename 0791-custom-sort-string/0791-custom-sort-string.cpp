class Solution {
public:
    string customSortString(string order, string s) {
        int mp[26]={0};
        for(auto&it:s)mp[it-'a']++;
        string result;
        for(auto&it:order){
            if(mp[it-'a']!=0){
                for(int i=0;i<mp[it-'a'];i++)result.push_back(it);
                mp[it-'a']=0;
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<mp[i]&&mp[i]!=0;j++)result.push_back(i+'a');
        }
        return result;
    }
};