class Solution {
private:
    void sub(vector<int>&v,vector<vector<int>>&res,vector<int>curr,int sum,int k,int target,int index){
        if(index==9){
            // int sum=0;
            // for(auto it: curr)sum++it;
            if(curr.size()==k&&sum==target){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back(v[index]);
        sum+=v[index];
        sub(v,res,curr,sum,k,target,index+1);
        sum-=v[index];
        curr.pop_back();
        sub(v,res,curr,sum,k,target,index+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int>v;
       for(int i=1;i<=9;i++)v.push_back(i);
       int sum=0;
       vector<vector<int>>res;vector<int>curr;
       sub(v,res,curr,sum,k,n,0);
       return res;
    }
};