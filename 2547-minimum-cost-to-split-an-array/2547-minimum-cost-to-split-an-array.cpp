class Solution {
private:
    int dp[1001];
    int sub(vector<int>&nums,int index,int k,int splitno){
        if(index==nums.size())return 0;
        if(dp[index]!=-1)return dp[index];
        map<int,int>mp;
        int cnt = 0;
        int ans = INT_MAX;
        for(int i=index;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2)cnt+=2;
            else if(mp[nums[i]]>2)++cnt;
            ans = min(ans,(cnt+k)+sub(nums,i+1,k,splitno+1));
        }
        return dp[index]=ans;
    }
public:
    int minCost(vector<int>& nums, int k) {  
        memset(dp,-1,sizeof(dp));
        return sub(nums,0,k,0);
    }
};