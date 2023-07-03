class Solution {
public:
    bool buddyStrings(string s, string goal) {
        map<char,int>mp1,mp2;
        for(auto&it:s)mp1[it]++;
        for(auto&it:goal)mp2[it]++;
        if(s==goal){
            for(auto&it:mp1){
                if(it.second>1)return 1;
            }
            return 0;
        }
        for(auto&it:mp1){
            if(mp2[it.first]==it.second)continue;
            else return 0;
        }
        for(auto&it:mp2){
            if(mp1[it.first]==it.second)continue;
            else  return 0;
        }
         if(s.size()!=goal.size())return 0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i])++cnt;
        }
        return cnt<=2;
    }
};