class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(auto&it:chars)mp[it]++;
        int len = 0;
        for(auto&it:words){
            map<char,int>mx;
            bool flag = 1;
            for(auto vt:it){
                mx[vt]++;
                if(!(mp[vt]>=mx[vt]))flag=0;
            }
            if(flag)len+=it.size();
        }
        return len;
    }
};