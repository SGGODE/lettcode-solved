class Solution {
private:
    bool sub(vector<vector<int>>&dp,vector<int>&nums,int index,int k,int last){
        if(index==nums.size()-1)return 1;
        bool ans = 0;
        if(dp[index][last+1]!=-1)return dp[index][last+1];
        if(k==-1){
            //cout<<index<<endl;
           if(nums[index+1]-nums[index]==1)ans=max(ans,sub(dp,nums,index+1,nums[index+1]-nums[index],index));
        }else{
            for(int i=index+1;i<nums.size();i++){
                if(nums[i]-nums[index]==k-1){
                    //cout<<i<<" -"<<endl;
                    ans=max(ans,sub(dp,nums,i,k-1,index));
                }
                if(nums[i]-nums[index]==k){
                   // cout<<i<<" -"<<endl;
                    ans=max(ans,sub(dp,nums,i,k,index));
                }
                if(nums[i]-nums[index]==k+1){
                   // cout<<i<<" +"<<endl;
                    ans=max(ans,sub(dp,nums,i,k+1,index));
                }
            }
        }
        return dp[index][last+1]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return sub(dp,stones,0,-1,-1);
    }
};