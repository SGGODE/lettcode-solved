class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>mp;
        for(auto&it:arr)mp[it]++;
        int num=0,len=0;
        for(auto&it:mp){
            if(it.second>len){
                len=it.second;
                num=it.first;
            }
        }
        return num;
    }
};