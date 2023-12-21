class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // int len = 0;
        // int lenend = 0;
        // for(auto&it:points){
        //     len = min(len,min(it[0],it[1]));
        //     lenend =  max(lenend,max(it[0],it[1]));
        // }
        vector<int>res;
        map<int,int>mp;
        for(auto&it:points){
            res.push_back(it[0]);
            mp[it[0]]=it[1];
        }
        sort(res.begin(),res.end());
        int len = 0;
        for(int i=1;i<res.size();i++){
            int length = (res[i]-res[i-1]);
            int breath = abs(mp[res[i]]-mp[res[i-1]]);
            len = max(len,(length));
        }
        return len;
    }
};