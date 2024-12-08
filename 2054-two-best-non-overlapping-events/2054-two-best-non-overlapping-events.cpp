class Solution {
//private:
    // int dp[100001][3];
    // int solve(vector<vector<int>> & nums , int index , int last , int calls){
    //     if(calls == 0)return 0;
    //     if(index == nums.size())return 0;
    //     if(dp[index][calls] != -1)return dp[index][calls];
    //     int ans = solve(nums , index + 1 , last , calls);
    //     if(last < nums[index][0] && calls != 0){
    //         ans = max(ans , nums[index][2] + solve(nums , index + 1 , nums[index][1] , calls - 1));
    //     }
    //     return dp[index][calls] = ans;
    // }
public:
    int maxTwoEvents(vector<vector<int>>&nums) {
       // memset(dp , -1 , sizeof(dp));
        sort(nums.begin() , nums.end());
     //   return solve(nums , 0 , -1 , 2);
        priority_queue<pair<int,int> , vector<pair<int,int>> , 
                                        greater<pair<int,int>>>pq;
        int Tempresult = 0 , Sum = 0;
        for(auto & it : nums){
            
            while(!pq.empty() && pq.top().first < it[0]){
                Tempresult = max(Tempresult , pq.top().second);
                pq.pop();
            }
            
            Sum = max(Sum , Tempresult + it[2]);
            pq.push({it[1] , it[2]});
        }
        return Sum;
    }
};