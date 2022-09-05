class Solution {
private:
   void view(vector<vector<int>>&v,vector<int>given,vector<int>get,int idx,int n){
       if(idx==n){
           v.push_back(get);
           return;
       }
       get.push_back(given[idx]);
       view(v,given,get,idx+1,n);
       get.pop_back();
       view(v,given,get,idx+1,n);
   } 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
        vector<vector<int>> v;
       vector<int>get;
       //v.push_back(get);
       view(v,nums,get,0,n);
       return v;
    }
};