class Solution {
// private:
//     int dp[100001][4];
//     int sub(vector<int>&nums,int index,int ops,int m_val,int mx_val){
//         if(index==nums.size())return mx_val - m_val;
        
//         int ans = 1e9;
//         ans = min(ans,sub(nums,index+1,ops,min(m_val,nums[index]),max(mx_val,nums[index])));
//         if(ops){
//             ans = min(ans,sub(nums,index+1,ops-1,m_val,mx_val));
//         }
//         return dp[index][ops]=ans;
//     }
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<=4)return 0;
        int result = INT_MAX;
        for(int i = 0 ; i < 4 ; i++){
            int m_val = 1e9;
            int mx_val = 0;
            for(int j = i ; j < n ; j++){
                m_val = min(m_val , nums[j]);
                mx_val = max(mx_val , nums[j]);
                if((i + ( n - (j+1)) ) <= 3) result = min(result , mx_val - m_val);
            }
        }
        return result;
    }
};