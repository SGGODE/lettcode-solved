class Solution {
private:
    bool balance(map<char,int>&mx,map<char,int>&mp){
        for(auto it:mx){
            if(it.second==0||(it.second==mp[it.first]))continue;
            else return 0;
        }
        return 1;
    }
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(auto it:s)mp[it]++;
        // vector<pair<char,int>>v;
        // for(auto it:mp){
        //     v.push({it.first,})
        // }
        map<char,int>mx(mp);
        int cnt=0;
        vector<int>res;
        for(auto it:s){
            --mx[it];
            ++cnt;
            if(mx[it]==0&&balance(mx,mp)){
                res.push_back(cnt);
                cnt=0;
            }
        }
        //if(cnt!=0)
        return res;
    }
};