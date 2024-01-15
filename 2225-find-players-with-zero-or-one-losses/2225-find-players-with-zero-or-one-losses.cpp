class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>winner,loser;
        for(auto&it:matches){
            winner[it[0]]++;
            loser[it[1]]++;
        }
        vector<int>res,res1;
        for(auto&it:winner){
            if(!loser.count(it.first))res.push_back(it.first);
        }
        for(auto&it:loser){
            if(it.second==1)res1.push_back(it.first);
        }
        return {res,res1};
    }
};