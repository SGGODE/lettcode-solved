class Solution {
private:
    int sub(vector<vector<int>>&xp,vector<int>&dp,int index,int last){
        if(index==xp.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 0;
        ans = sub(xp,dp,index+1,last);
        vector<int>::iterator it;
        if(last==-1||xp[last][1]<=xp[index][0]){
           auto lowerBoundIt = std::lower_bound(xp.begin()+index, xp.end(), std::vector<int>{xp[index][1]},
                        [](const std::vector<int>& a, const std::vector<int>& b) {
                            return a[0] < b[0];
                        });
            int lowerBoundIndex = std::distance(xp.begin(), lowerBoundIt);
            if(lowerBoundIndex<xp.size())ans = max(ans,xp[index][2]+sub(xp,dp,lowerBoundIndex,index));
            else ans = max(ans,xp[index][2]);
        }
        return dp[index]=ans;        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>>xp;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            xp.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(xp.begin(),xp.end());
        return sub(xp,dp,0,-1);
    }
};