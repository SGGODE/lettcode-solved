class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp1;
        map<int,int>mp2;
        int n=matches.size();
        for(int i=0;i<n;i++){
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        vector<vector<int>>res;
        vector<int>v;
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end()){
                v.push_back(it.first);
            }
        }
        res.push_back(v);
        v.clear();
        for(auto it:mp2){
            if(it.second==1){
                v.push_back(it.first);
            }
        }
        res.push_back(v);
        return res;
    }
};