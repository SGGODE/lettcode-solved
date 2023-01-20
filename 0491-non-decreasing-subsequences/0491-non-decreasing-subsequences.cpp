class Solution {
private:
    void allsubsequence(vector<vector<int>>&v,vector<int>&nums,vector<int>&x,int index,int n){
        if(index>=n){
            int f=x[0];bool flag=0;
            for(auto it:x){
                if(it>=f){
                    f=it;
                }else{
                  flag=1;
                   break; 
                } 
            }
            if(!flag&&x.size()>=2)
              v.push_back(x);
            return;
        }
         x.push_back(nums[index]);
        allsubsequence(v,nums,x,index+1,n);
        x.pop_back();
        allsubsequence(v,nums,x,index+1,n);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>x;
        int n=nums.size();
        allsubsequence(v,nums,x,0,n);
        map<vector<int>,int>mp;
        for(auto it:v){
            mp[it]++;
        }
        // vector<vector<int>>res;
        // for(auto it:v){
        //     vector<int>dump;
        //     for(auto vt:it)dump.push_back(vt);
        //     res.push_back(dump);
        // }
        // return res
       vector<vector<int>>res;
        for(auto it:mp){
            res.push_back(it.first);
        }
        return res;
    }
};