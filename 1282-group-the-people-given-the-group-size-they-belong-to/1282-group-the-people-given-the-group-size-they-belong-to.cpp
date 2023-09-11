class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>&nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        // for(auto&it:mp){
        //     cout<<it.first<<endl;
        //     for(auto vt:it.second)cout<<vt<<" ";
        //     cout<<endl;
        // }
        vector<vector<int>>res;
        for(auto&it:mp){
            vector<int>store=it.second;
            int m =store.size();
            //cout<<m<<endl;
            vector<int>temp;
            int round = m/it.first;
           // cout<<round<<endl;
            int index=0;
            while(round!=0){
                  int cnt=0;
                  while(cnt!=it.first){
                      ++cnt;
                   //   cout<<store[index]<<endl;
                      temp.push_back(store[index]);
                      ++index;
                  }
                res.push_back(temp);
                --round;
                temp.clear();
            }
        }
        return res;
    }
};