class Solution {
private:
    int cnt=0;
    void solve(vector<int>&nums,int sum,int index,vector<vector<int>>&dp,vector<int>&temp){
       // if(sum==0)return 1;
        if(index==nums.size()){
            if(!temp.empty()){
            int mi=*min_element(temp.begin(),temp.end());
            int ma=*max_element(temp.begin(),temp.end());
            if(mi+ma<=sum)++cnt;
            }
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,sum,index+1,dp,temp);
        temp.pop_back();
        solve(nums,sum,index+1,dp,temp);
    }
public:
    int numSubseq(vector<int>& nums, int target) {
    //   int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(target+1,-1));
//         //return 
//         vector<int>temp;
//         solve(nums,target,0,dp,temp);
//         // int cnt=0;
//         // for(int i=1;i<=target;i++){
//         //     if(dp[n-1][i]!=1)++cnt;
//         // }
//        return cnt;
//          sort(nums.begin(),nums.end());
//          int last=n-1;
//        long long int res=0;
//         int mod=1e9+7;
//         for(int i=0;i<n;i++){
//             while(nums[i]+nums[last]>target&&i<=last)--last;
//             if(last>=i){
//                // res=res+pow(2,(last-i));
//                 long long x=pow(2,(last-i));
//                 res=(res+x)%mod;
                
//             }
//         }
//         return res%mod;
        int count =0 ; 
        int n = nums.size();
        vector<int>pow(n,1);
        sort(nums.begin(), nums.end());
        for(int i =1;i<n;i++){
            pow[i] = (pow[i-1] * 2) % (1000000007 );
        }
        int left =0 ; int right = n-1;
        while(left<=right){
            if(nums[left]  + nums[right] > target) right--;
            else{
                count  = (count + pow[right-left] ) % (1000000007 );
                left++;
            }
        }
        return count;
    }
};