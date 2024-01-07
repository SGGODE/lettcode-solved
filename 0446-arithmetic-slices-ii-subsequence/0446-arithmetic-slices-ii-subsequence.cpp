class Solution {
private:
    
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // map<pair<int,int>,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(mp.count({j,nums[j]-nums[i]})){
        //             mp[{i,nums[j]-nums[i]}]=1+mp[{j,nums[j]-nums[i]}];
        //         }else{
        //              mp[{i,nums[j]-nums[i]}]=1;
        //         }
        //     }
        // }
        // int cnt = 0;
        // for(auto&it:mp){
        //     if(it.second>=2)++cnt;
        // }
        // return cnt;
        int n = nums.size();
        
        // declare a dp array of unordered_map
        
        vector<unordered_map<long, long>> dp(n + 1);
        
        // dp[i][diff] will store the no. of subsequence with common difference of diff, till ith index
        
        long ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                long diff = (long) nums[i] - long(nums[j]);
                
                // update ans
                
                ans += dp[j][diff];
                
                // update dp[i][diff]
                
                dp[i][diff] += dp[j][diff];
                
                dp[i][diff]++;
            }
        }
        
        return ans;
    }
};