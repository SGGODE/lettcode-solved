class Solution {
private:
    vector<vector<int>>v;
    void sum(vector<int>&given,vector<int>get,int tar,int idx,int s,int n){
        if(idx==n){
            if(tar==0){
                v.push_back(get);
            }
            return;
        }
        if(given[idx]<=tar){
        //s+=given[idx];
        get.push_back(given[idx]);
        sum(given,get,tar-given[idx],idx,s,n);
       // s-=given[idx];
        get.pop_back();
        }
        sum(given,get,tar,idx+1,s,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        //vector<vector<int>>result;
        vector<int>given=candidates;
        vector<int>s;
        sum(candidates,s,target,0,0,n);
        return v; 
    }
};